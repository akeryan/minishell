/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:42:56 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/26 17:07:53 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "data.h"

void	print_tree(t_node *node, int level);

char	*token_type_to_a(t_token_type type)
{
	if (type == EOF_TOKEN)
		return ("EOF");
	else if (type == NEWLINE_TOKEN)
		return ("newline");
	else if (type == PIPE)
		return ("|");
	else if (type == DLESS)
		return ("<<");
	else if (type == DGREAT)
		return (">>");
	else if (type == LESS)
		return ("<");
	else if (type == GREAT)
		return (">");
	else if (type == WORD)
		return ("word");
	else if (type == EMPTY)
		return ("empty");
	return ("ERROR!!!");
}

char	*node_type_to_a(t_node_type	type)
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

void	print_tabs(int level)
{
	int	i;

	i = 0;
	while (i < level)
	{
		printf("\t");
		i++;
	}
}

char	*str_or_null(char *str)
{
	if (str)
		return (str);
	else
		return ("(null)");
}

void	print_cases(int level, t_node *node)
{
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
}
