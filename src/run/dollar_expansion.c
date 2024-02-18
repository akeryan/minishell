/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:55:06 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/18 21:48:22 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "expansion.h"
#include "libft.h"
#include "word_list.h"

void	dollar_expansion(char **word, t_data *data)
{
	char		*ptr;
	char		*current;
	t_word_node	*head;	
	t_word_node *tmp;

	if (!word)
		return ;
	current = *word;
	while (1)
	{
		ptr = is_there_unquoted_dollar(current);
		if (!ptr)
		{
			if (ft_strlen(current) > 0)
				add_word_back(&head, new_word(current));	
			break ;
		}
		if (ptr != current)
		{
			if ((*(ptr + 1) == '\0' || *(ptr + 1) == '"') && !ft_strchr(current + 1, '$'))
			{
				add_word_back(&head, new_word(current));	
				break ;
			}
			add_word_back(&head, new_word_m(ft_strdup(current, ptr - current)));
			current = ptr;
		}
		if (*(ptr + 1) == '\0')
		{
			add_word_back(&head, new_word("$"));
			break ;
		}
		if (*(ptr + 1) == '$' || *(ptr + 1) == '?')
		{
			if (*(ptr + 1) == '$')
				add_word_back(&head, new_word_m(ft_itoa(data->dbl_dollar)));
			else
				add_word_back(&head, new_word_m(ft_itoa(data->exit_status)));
			ptr+=2;
			current = ptr;
			continue;
		}
		while(*(ptr + 1) != '$' && *(ptr +1) != '\0' && *(ptr + 1) != '"' && *(ptr + 1) != '\'')
			ptr++;
		ptr++;
		if (ptr != current)
		{
			add_word_back(&head, new_word_m(ft_strdup(current, ptr - current)));
			current = ptr;
		}
	}
	tmp = head;
	while (1)
	{
		if (tmp)
			printf("EXIT: %s\n", tmp->word);
		if (tmp->next)
			tmp = tmp->next;
		else
			break;
	}
}

int	apply_expansions(char **word, t_data *d)
{
	dollar_expansion(word, d);
	tilde_expansion(word, d->env);
	return (0);
}
