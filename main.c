/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:21:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/10 19:17:52 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <errno.h>
#include "libft.h"
#include "ft_printf.h"
#include "minishell.h"
#include "parse.h"
#include "rules.h"
#include "main_utils.h"

static char	*token_type_to_a(t_token_type type)
{
	if (type == EOF_TOKEN)
		return ("EOF");
	else if (type == NEWLINE_TOKEN)
		return ("NEWLINE");
	else if (type == PIPE)
		return ("PIPE");
	else if (type == DLESS)
		return ("DLESS");
	else if (type == DGREAT)
		return ("DGREAT");
	else if (type == LESS)
		return ("LESS");
	else if (type == GREAT)
		return ("GREAT");
	else if (type == WORD)
		return ("WORD");
	else if (type == EMPTY)
		return ("EMPTY");
	return ("ERROR!!!");
}

static char	*node_type_to_a(t_node_type	type)
{
	if (type == PROGRAM)
		return ("PROGRAM");
	else if (type == PIPELINE)
		return ("PIPELINE");
	else if (type == COMMAND)
		return ("COMMAND");
	else if (type == PREFIX)
		return ("CMD_PREFIX");
	else if (type == SUFFIX)
		return ("CMD_SUFFIX");
	else if (type == IO_REDIR)
		return ("IO_REDIRECT");
	else if (type == NEWLINE_LIST)
		return ("NEWLINE_LIST");
	else
		return ("ERROR!!!");
}

static void	print_tabs(int level)
{
	int	i;

	i = 0;
	while (i < level)
	{
		printf("\t");
		i++;
	}
}

static char	*str_or_null(char *str)
{
	if (str)
		return (str);
	else
		return ("(null)");
}

static void	print_tree(t_node *node, int level)
{
	if (!node)
	{
		printf("(null)\n");
		return ;
	}
	if (level != 0)
	{
		printf("\n");
		print_tabs(level);
		printf("{\n");
	}
	print_tabs(level);
	printf("NODE: %s\n", str_or_null(node_type_to_a(node->node_type)));
	print_tabs(level);
	printf("WORD: %s\n", str_or_null(node->word));
	print_tabs(level);
	printf("TOKEN: %s\n", str_or_null(token_type_to_a(node->token_type)));
	print_tabs(level);
	printf("LEFT: ");
	print_tree(node->left, level + 1);
	print_tabs(level);
	printf("NEWL_PTR: ");
	print_tree(node->newl_ptr, level + 1);
	print_tabs(level);
	printf("RIGHT: ");
	print_tree(node->right, level + 1);
	if (level != 0)
	{
		print_tabs(level);
		printf("}\n");
	}
}

int	main(void)
{
	t_grammar	grammar;
	t_node		*root;

	grammar = setup_grammar();
	while (1)
	{
		root = parse(PROGRAM, &grammar);
		print_tree(root, 0);
		if (errno != 0)
			perror("ERRNO");
		if (!root)
		{
			if (peek_token().type == EOF_TOKEN)
			{
				printf(EXIT_MSG);
				return (EXIT_SUCCESS);
			}
			else
			{
				ft_printf(2, "syntax error near unexpected token: '%s'\n", token_type_to_a(peek_token().type));
				while (consume_token().type != NEWLINE_TOKEN)
					;
			}
		}
		run_cmd(root);
	}
	return (EXIT_SUCCESS);
}
