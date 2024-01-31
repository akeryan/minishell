/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:42:18 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/31 18:05:28 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include <errno.h>

static t_recipe	find_recipe(t_node_type book, int rec_num, t_grammar *grammar)
{
	int		i;

	i = 0;
	while (i < BOOKS_NUMBER)
	{
		if (grammar->book[i].type == book_type)
			return (grammar->book[i]);
		i++;
	}
	errno = EINVAL;
	book.size = 0;
	return (book);
}

t_node	*parse(t_node_type book_type, t_grammar *grammar)
{
	t_book	book;

	book = find_book(book_type, grammar);
	if (book.size == 0)
		return (NULL);
}
