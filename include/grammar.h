/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:24:27 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/26 17:22:53 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAMMAR_H
# define GRAMMAR_H

# define BOOKS_NUMBER	7
# define MAX_INGS		4
# define MAX_RECIPES	5

# include "node.h"

typedef enum e_ingtype
{
	BOOK = 0,
	TOKEN = 1
}	t_ingtype;

typedef union u_ing_data
{
	t_token_type	token;
	t_node_type		book_type;
}	t_ing_data;

typedef struct s_ingredient
{
	int			optional;
	t_ingtype	type;
	t_ing_data	ing_data;
}	t_ingredient;

typedef struct s_recipe
{
	int				size;
	t_ingredient	ing[MAX_INGS];
}	t_recipe;

typedef struct s_book
{
	int				size;
	t_recipe		recipe[MAX_RECIPES];
}	t_book;

typedef struct s_grammar
{
	int		size;
	t_book	book[BOOKS_NUMBER];
}	t_grammar;

t_ingredient	book_to_ing(t_node_type node);
t_ingredient	token_to_ing(t_token_type token);

#endif
