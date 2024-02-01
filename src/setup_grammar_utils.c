/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_grammar_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:18:53 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/01 11:47:15 by dabdygal         ###   ########.fr       */
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

	command.type = COMMAND;
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
cmd_prefix	: io_redirect	cmd_prefix
            | io_redirect
 */

t_book	book_cmd_prefix(void)
{
	t_book	cmd_prefix;

	cmd_prefix.type = PREFIX;
	cmd_prefix.size = 2;	
	cmd_prefix.recipe[0].size = 2;
	cmd_prefix.recipe[0].ing[0] = book_to_ing(IO_REDIR);
	cmd_prefix.recipe[0].ing[1] = book_to_ing(PREFIX);

	cmd_prefix.recipe[1].size = 1;
	cmd_prefix.recipe[1].ing[0] = book_to_ing(IO_REDIR);
	return (cmd_prefix);
}

/*
cmd_suffix	: io_redirect	cmd_suffix
            | io_redirect
            | WORD			cmd_suffix
            | WORD
*/
t_book	book_cmd_suffix(void)
{
	t_book	cmd_suffix;

	cmd_suffix.type = SUFFIX;
	cmd_suffix.size = 4;
	cmd_suffix.recipe[0].size = 2;
	cmd_suffix.recipe[0].ing[0] = book_to_ing(IO_REDIR);
	cmd_suffix.recipe[0].ing[1] = book_to_ing(SUFFIX);
	cmd_suffix.recipe[1].size = 1;
	cmd_suffix.recipe[1].ing[0] = book_to_ing(IO_REDIR);
	cmd_suffix.recipe[2].size = 2;
	cmd_suffix.recipe[2].ing[0] = token_to_ing(WORD);
	cmd_suffix.recipe[2].ing[1] = book_to_ing(SUFFIX);
	cmd_suffix.recipe[3].size = 1;
	cmd_suffix.recipe[3].ing[0] = token_to_ing(WORD);
	return (cmd_suffix);
}

/*
io_redirect	: LESS		WORD
            | GREAT		WORD
            | DGREAT	WORD
        	| DLESS		WORD
*/
t_book	book_io_redir(void)
{
	t_book	io_redir;

	io_redir.type = IO_REDIR;
	io_redir.size = 4;
	io_redir.recipe[0].size = 2;
	io_redir.recipe[0].ing[0] = token_to_ing(LESS);
	io_redir.recipe[0].ing[1] = token_to_ing(WORD);
	io_redir.recipe[1].size = 2;
	io_redir.recipe[1].ing[0] = token_to_ing(GREAT);
	io_redir.recipe[1].ing[1] = token_to_ing(WORD);
	io_redir.recipe[2].size = 2;
	io_redir.recipe[2].ing[0] = token_to_ing(DGREAT);
	io_redir.recipe[2].ing[1] = token_to_ing(WORD);
	io_redir.recipe[3].size = 2;
	io_redir.recipe[3].ing[0] = token_to_ing(DLESS);
	io_redir.recipe[3].ing[1] = token_to_ing(WORD);
	return (io_redir);
}

/*
newline_list	: NEWLINE	newline_list
                | NEWLINE
                | empty
*/
t_book	book_newline_list(void)
{
	t_book	newline_list;

	newline_list.type = NEWLINE_LIST;
	newline_list.size = 3;
	newline_list.recipe[0].size = 2;
	newline_list.recipe[0].ing[0] = token_to_ing(NEWLINE_TOKEN);
	newline_list.recipe[0].ing[1] = book_to_ing(NEWLINE_LIST);
	newline_list.recipe[1].size = 1;
	newline_list.recipe[1].ing[0] = token_to_ing(NEWLINE_TOKEN);
	newline_list.recipe[2].size = 1;
	newline_list.recipe[2].ing[0] = token_to_ing(EMPTY);
	return (newline_list);
}
