/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_grammar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:36:53 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/29 18:43:39 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

t_ingredient	book_to_ing(t_node_type node)
{
	t_ingredient	ing;

	ing.type = BOOK;
	ing.optional = 0;
	if (node == NEWLINE_LIST)
		ing.optional = 1;
	ing.ing_data.book_type = node;
	return (ing);
}

t_ingredient	token_to_ing(t_token_type token)
{
	t_ingredient	ing;

	ing.type = TOKEN;
	ing.optional = 0;
	ing.ing_data.token = token;
	return (ing);
}

/**
 * program	: newline_list
 * 			| newline_list pipeline
*/
static t_book	book_program(void)
{
	t_book	program;

	program.size = 2;
	{
		program.recipe[0].size = 1;
		program.recipe[0].ing[0] = book_to_ing(NEWLINE_LIST);
	}
	{
		program.recipe[1].size = 2;
		program.recipe[1].ing[0] = book_to_ing(NEWLINE_LIST);
		program.recipe[1].ing[1] = book_to_ing(PIPELINE);
	}
	return (program);
}

/**
 * pipeline	: command
 * 			| command	PIPE	newline_list	pipeline
*/
static t_book	book_pipeline(void)
{
	t_book	pipeline;

	pipeline.size = 2;
	{
		pipeline.recipe[0].size = 1;
		pipeline.recipe[0].ing[0] = book_to_ing(COMMAND);
	}
	{
		pipeline.recipe[1].size = 4;
		pipeline.recipe[1].ing[0] = book_to_ing(COMMAND);
		pipeline.recipe[1].ing[1] = token_to_ing(PIPE);
		pipeline.recipe[1].ing[2] = book_to_ing(NEWLINE_LIST);
		pipeline.recipe[1].ing[3] = book_to_ing(PIPELINE);
	}
	return (pipeline);
}

t_grammar	setup_grammar(t_recipe *recipe)
{
	t_grammar	grammar;

	grammar.book[0] = book_program();
	grammar.book[1] = book_pipeline();
	grammar.book[2] = book_command();
	grammar.book[3] = book_cmd_prefix();
}
