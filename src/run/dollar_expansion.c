/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:55:06 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/18 23:23:09 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "expansion.h"
#include "libft.h"
#include "word_list.h"

static int	func_1(char **current, t_word_node **head)
{
	if (ft_strlen(*current) > 0)
		add_word_back(head, new_word(*current));
	return (1);
}

static void	func_2(t_word_node **head, char **current, char **ptr)
{
	add_word_back(head, new_word_m(ft_strdup(*current, *ptr - *current)));
	*current = *ptr;
}

static void	func_3(char **ptr, t_word_node **head, t_data *data, char **current)
{
	if (*(*ptr + 1) == '$')
		add_word_back(head, new_word_m(ft_itoa(data->dbl_dollar)));
	else
		add_word_back(head, new_word_m(ft_itoa(data->exit_status)));
	*ptr += 2;
	*current = *ptr;
}

static void	func_4(char **ptr, char **current, t_word_node **head)
{
	while (*(*ptr + 1) != '$' && *(*ptr + 1) != '\0' && *(*ptr + 1) \
		!= '"' && *(*ptr + 1) != '\'')
		(*ptr)++;
	(*ptr)++;
	if (*ptr != *current)
	{
		add_word_back(head, new_word_m(ft_strdup(*current, *ptr - *current)));
		*current = *ptr;
	}
}

static int	func_5(char **ptr, char **current)
{
	if ((*(*ptr + 1) == '\0' || *(*ptr + 1) == '"') && \
		!ft_strchr(*current + 1, '$'))
		return (1);
	else
		return (0);
}

static int func_6(t_word_node **head, char **current)
{
	add_word_back(head, new_word(*current));
	return (1);
}

static int func_7(t_word_node **head)
{
	add_word_back(head, new_word("$"));
	return (1);
}

void	dollar_expansion(char **word, t_data *data)
{
	char		*ptr;
	char		*current;
	t_word_node	*head;	

	current = *word;
	while (1)
	{
		ptr = is_there_unquoted_dollar(current);
		if (!ptr && func_1(&current, &head))
			break ;
		if (ptr != current)
		{
			if (func_5(&ptr, &current) && func_6(&head, &current))
				break ;
			func_2(&head, &current, &ptr);
		}
		if (*(ptr + 1) == '\0' && func_7(&head))
			break ;
		if (*(ptr + 1) == '$' || *(ptr + 1) == '?')
		{
			func_3(&ptr, &head, data, &current);
			continue ;
		}
		func_4(&ptr, &current, &head);
	}
}

int	apply_expansions(char **word, t_data *d)
{
	dollar_expansion(word, d);
	tilde_expansion(word, d->env);
	return (0);
}
