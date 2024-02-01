/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:42:18 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/01 11:10:42 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include "libft.h"
#include <stdlib.h>
#include <errno.h>

static t_recipe	find_recipe(t_node_type book, int rec_num, t_grammar *grammar)
{
	int			i;
	t_recipe	recipe;

	i = 0;
	while (i < BOOKS_NUMBER)
	{
		if (grammar->book[i].type == book)
			break ;
		i++;
	}
	if (i == BOOKS_NUMBER || rec_num > grammar->book[i].size || rec_num < 1)
	{
		errno = EINVAL;
		recipe.size = 0;
		return (recipe);
	}
	return (grammar->book[i].recipe[rec_num - 1]);
}

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

static int	fill_node(t_node *node, t_book *book)
{
}

t_node	*parse(t_node_type node_type, t_grammar *grammar)
{
	t_node		*node;
	t_book		*book;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->node_type = node_type;
	book = find_book(node_type, grammar);
	if (!book || !fill_node(node, book))
	{
		ft_free(&node);
		return (NULL);
	}
	return (node);
}
