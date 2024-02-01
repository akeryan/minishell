/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_grammar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:36:53 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/01 11:40:38 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

t_ingredient	book_to_ing(t_node_type node)
{
	t_ingredient	ing;

	ing.type = BOOK;
	ing.ing_data.book_type = node;
	return (ing);
}

t_ingredient	token_to_ing(t_token_type token)
{
	t_ingredient	ing;

	ing.type = TOKEN;
	ing.ing_data.token = token;
	return (ing);
}

/**
 * program	: newline_list pipeline
 * 			| newline_list
*/
static t_book	book_program(void)
{
	t_book	program;

	program.type = PROGRAM;
	program.size = 2;
	{
		program.recipe[0].size = 2;
		program.recipe[0].ing[0] = book_to_ing(NEWLINE_LIST);
		program.recipe[0].ing[1] = book_to_ing(PIPELINE);
	}
	{
		program.recipe[1].size = 1;
		program.recipe[1].ing[0] = book_to_ing(NEWLINE_LIST);
	}
	return (program);
}

/**
 * pipeline	: command	NEWLINE
 * 			| command	PIPE	newline_list	pipeline
*/
static t_book	book_pipeline(void)
{
	t_book	pipeline;

	pipeline.type = PIPELINE;
	pipeline.size = 2;
	{
		pipeline.recipe[0].size = 2;
		pipeline.recipe[0].ing[0] = book_to_ing(COMMAND);
		pipeline.recipe[0].ing[1] = token_to_ing(NEWLINE_TOKEN);
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

/**
 * @brief Sets up grammar rules.
 * @details Sets up grammar rules as a respective structure.
 * Any token may be considered as "EMPTY" token.
 * @return Returns a t_grammar structure with rules setup as substructures.
 * @warning Handle "EMPTY" token in parser, as tokenizer may not recignize it.
*/
t_grammar	setup_grammar(void)
{
	t_grammar	grammar;

	grammar.book[0] = book_program();
	grammar.book[1] = book_pipeline();
	grammar.book[2] = book_command();
	grammar.book[3] = book_cmd_prefix();
	grammar.book[4] = book_cmd_suffix();
	grammar.book[5] = book_io_redir();
	grammar.book[6] = book_newline_list();
	return (grammar);
}
