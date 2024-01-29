/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_grammar_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:18:53 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/29 18:48:57 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"

/**
 * command	: cmd_prefix	WORD		cmd_suffix
        	| cmd_prefix	WORD       
            | cmd_prefix
            | WORD			cmd_suffix
            | WORD
*/
t_book	book_command(void)
{
	t_book	command;

	command.size = 5;
	command.recipe[0].size = 3;
	command.recipe[0].ing[0] = book_to_ing(PREFIX);
	command.recipe[0].ing[1] = token_to_ing(WORD);
	command.recipe[0].ing[2] = book_to_ing(SUFFIX);
	command.recipe[1].size = 2;
	command.recipe[1].ing[0] = book_to_ing(PREFIX);
	command.recipe[1].ing[1] = token_to_ing(WORD);
	command.recipe[2].size = 1;
	command.recipe[2].ing[0] = book_to_ing(PREFIX);
	command.recipe[3].size = 2;
	command.recipe[3].ing[0] = token_to_ing(WORD);
	command.recipe[3].ing[1] = book_to_ing(SUFFIX);
	command.recipe[4].size = 1;
	command.recipe[4].ing[0] = token_to_ing(WORD);
	return (command);
}
/* 
cmd_prefix	: io_redirect
            | io_redirect  cmd_prefix
 */

t_book	book_cmd_prefix(void)
{
	t_book	cmd_prefix;

	cmd_prefix.size = 2;
	cmd_prefix.recipe[0].size = 1;
	cmd_prefix.recipe[0].ing[0] = book_to_ing(IO_REDIR);
	cmd_prefix.recipe[1].size = 2;
	cmd_prefix.recipe[1].ing[0] = book_to_ing(IO_REDIR);
	cmd_prefix.recipe[1].ing[1] = book_to_ing(PREFIX);
	return (cmd_prefix);
}
