/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:55:06 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/20 16:22:53 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "dollar_expansion.h"
#include "expansion.h"
#include "libft.h"
#include "word_list.h"
#include "error_handling.h"

static int	func_6(t_word_node **head, char **current)
{
	add_word_back(head, new_word(*current));
	return (1);
}

static int	func_7(t_word_node **head)
{
	add_word_back(head, new_word("$"));
	return (1);
}

void	expand_word(t_word_node *node, char ***env)
{
	char	*value;
	char	*tmp;

	if (*node->word == '$' && ft_strlen(node->word) > 1)
	{
		value = ft_getenv(node->word + 1, *env);
		printf("ENV_value: %s\n", value);
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

char	*join_words(t_word_node *head, char ***env)
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

void	dollar_expansion(char **word, t_data *data)
{
	char		*ptr;
	char		*current;
	t_word_node	*head;	

	if (!is_there_unquoted_dollar(*word))
		return ;
	printf("	DOLLAR: ther is unquoted dollar\n");
	current = *word;
	printf("	CURRENT: %s\n", current);
	head = NULL;
	while (1)
	{
		ptr = is_there_unquoted_dollar(current);
		if (!ptr && func_1(&current, &head))
			break ;
		printf("		ONE\n");
		if (ptr != current)
		{
			if (func_5(&ptr, &current) && func_6(&head, &current))
				break ;
			printf("			ONE_1\n");
			func_2(&head, &current, &ptr);
			printf("			ONE_2\n");
		}
		printf("		TWO\n");
		if (*(ptr + 1) == '\0' && func_7(&head))
			break ;
		printf("		THREE\n");
		if (func_3(&ptr, &head, data, &current))
			continue ;
		printf("		FOUR\n");
		func_4(&ptr, &current, &head);
		printf("		FIVE\n");
	}
	printf("	DOLLAR:	after the while loop\n");
	free(*word);
	*word = join_words(head, data->env);
	free_word_list(head);
}
