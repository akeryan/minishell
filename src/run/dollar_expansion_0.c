/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion_0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:55:06 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/23 00:07:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "dollar_expansion.h"
#include "expansion.h"
#include "libft.h"
#include "word_list.h"
#include "error_handling.h"

void	expand_word(t_word_node *node, char ***env)
{
	char	*value;
	char	*tmp;

	if (*node->word == '$' && *(node->word + 1) != ' ' && ft_strlen(node->word) > 1)
	{
		value = ft_getenv_aram(node->word + 1, *env);
		if (value)
		{
			tmp = ft_strdup(value);
			if (!tmp)
				panic_malloc();
		}
		else
			tmp = NULL;
		free (node->word);
		node->word = tmp;
	}
}

static char	*join_words(t_word_node *head, char ***env)
{
	char	*out;
	char	*tmp;	

	out = NULL;
	while (head)
	{
		expand_word(head, env);
		if (head->word)
		{
			if (!out)
				tmp = ft_strdup(head->word);
			else
				tmp = ft_strjoin(out, head->word);
			if (!tmp)
				panic_malloc();
			free (out);
			out = tmp;
		}
		if (head->next)
			head = head->next;
		else
			head = NULL;
	}
	return (out);
}

static void	tokenizer(char **ptr, char **current, t_word_node **head, \
	t_data *data)
{
	while (1)
	{
		*ptr = is_there_unquoted_dollar(*current);
		if (!*ptr && func_1(current, head))
			break ;
		if (*ptr != *current)
		{
			if (func_5(ptr, current) && func_6(head, current))
				break ;
			func_2(head, current, ptr);
		}
		if (*(*ptr + 1) == '\0' && func_7(head))
			break ;
		if (func_3(ptr, head, data, current))
			continue ;
		func_4(ptr, current, head);
	}
}

void	dollar_expansion(char **word, t_data *data)
{
	char		*ptr;
	char		*current;
	t_word_node	*head;	

	if (!is_there_unquoted_dollar(*word))
		return ;
	current = *word;
	head = NULL;
	tokenizer(&ptr, &current, &head, data);
	free(*word);
	*word = join_words(head, &data->env);
	free_word_list(head);
}
