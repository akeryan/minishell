/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:42:18 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/05 15:33:59 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "libft.h"
#include "parse.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

static	t_book	*find_book(t_node_type node_type, t_grammar *grammar)
{
	int		i;

	i = 0;
	while (i < BOOKS_NUMBER)
	{
		if (grammar->book[i].type == node_type)
			return (&grammar->book[i]);
		i++;
	}
	errno = EINVAL;
	return (NULL);
}

static int	parse_token(t_node *node)
{
	t_token	token;

	token = consume_token();
	if (token.type != WORD)
		node->token_type = token.type;
	else
	{
		if (node->token_type == DLESS)
		{
			node->word = here_file(token);
			if (!node->word)
				return (0);
		}
		else
		{
			node->word = ft_substr(token.slice.location, 0, token.slice.length);
			if (!node->word)
				return (0);
		}
	}
	return (1);
}

static int	parse_ing(t_ingredient *ing, t_node *node, t_grammar *grammar)
{
	t_node	*ptr;

	if (ing->type == BOOK)
	{
		ptr = parse(ing->ing_data.book_type, grammar);
		if (!ptr)
			return (0);
		if (ing->ing_data.book_type == NEWLINE_LIST)
			node->newl_ptr = ptr;
		else
		{
			if (!node->left)
				node->left = ptr;
			else
				node->right = ptr;
		}
	}
	else if (ing->ing_data.token == EMPTY && peek_token().type != EOF_TOKEN)
		return (1);
	else if (peek_token().type == ing->ing_data.token && parse_token(node))
		return (1);
	else
		return (0);
	return (1);
}

static int	fill_node(t_node *node, t_book *book, t_grammar *grammar)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < book->size)
	{
		while (j < book->recipe[i].size)
		{
			if (parse_ing(&book->recipe[i].ing[j], node, grammar) == 0)
			{
				if (errno != 0)
					return (0);
				break ;
			}
			j++;
		}
		if (j == book->recipe[i].size)
			break ;
		i++;
	}
	if (i == book->size)
		return (0);
	return (1);
}

t_node	*parse(t_node_type node_type, t_grammar *grammar)
{
	t_node		*node;
	t_book		*book;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->node_type = node_type;
	node->left = NULL;
	node->right = NULL;
	node->word = NULL;
	node->token_type = EMPTY;
	node->newl_ptr = NULL;
	book = find_book(node_type, grammar);
	if (!book || !fill_node(node, book, grammar))
	{
		erase_node(&node);
		return (NULL);
	}
	return (node);
}
