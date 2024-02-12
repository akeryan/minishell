/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:42:18 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/12 15:22:00 by dabdygal         ###   ########.fr       */
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

static int	pars_tok(t_node *node, char *ps2)
{
	t_token	token;

	token = consume_token(ps2);
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

int	parse_ing(t_ingredient *ing, t_node *node, t_grammar *gr, char *ps2)
{
	t_node	*ptr;

	if (ing->type == BOOK)
	{
		ptr = parse(ing->ing_data.book_type, gr, ps2);
		if (!ptr)
			return (0);
		if (ing->ing_data.book_type == NEWLINE_LIST)
			node->newl_ptr = ptr;
		else
		{
			if (!node->left && ing->ing_data.book_type != SUFFIX)
				node->left = ptr;
			else
				node->right = ptr;
		}
	}
	else if (ing->ing_data.token == EMPTY && peek_token(ps2).type != EOF_TOKEN)
		return (1);
	else if (peek_token(ps2).type == ing->ing_data.token && pars_tok(node, ps2))
		return (1);
	else
		return (0);
	return (1);
}

t_node	*parse(t_node_type node_type, t_grammar *grammar, char *ps2)
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
	if (!book || !fill_node(node, book, grammar, ps2))
	{
		if (node_type == PROGRAM && errno == MSH_SYNTAX)
			errno = 0;
		erase_node(&node);
		return (NULL);
	}
	return (node);
}
