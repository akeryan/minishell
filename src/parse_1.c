/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:18:18 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/23 19:40:15 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include "minishell.h"
#include "tokens.h"
#include "libft.h"

extern int	g_signal;

static int	process_ing(t_ingredient *ing, t_node *n, t_grammar *gr, char *ps2)
{
	int				x;
	t_token_type	t;

	t = NEWLINE_TOKEN;
	if ((n->newl_ptr && n->newl_ptr->token_type == t) || n->token_type == t)
		x = parse_ing(ing, n, gr, "> ");
	else
		x = parse_ing(ing, n, gr, ps2);
	return (x);
}

int	fill_node(t_node *node, t_book *book, t_grammar *grammar, char *ps2)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < book->size)
	{
		while (j < book->recipe[i].size)
		{
			if (process_ing(&book->recipe[i].ing[j], node, grammar, ps2) == 0)
			{
				if (errno == 0 && node->node_type == IO_REDIR && j > 0)
					errno = MSH_SYNTAX;
				break ;
			}
			j++;
		}
		if (j == book->recipe[i].size || errno != 0)
			break ;
		i++;
	}
	if (i == book->size || errno != 0)
		return (0);
	return (1);
}

t_node	*build_tree(t_grammar *grammar, char *ps2)
{
	t_node	*root;

	root = parse(PROGRAM, grammar, NULL);
	while (!root && g_signal == SIGINT)
	{
		while (consume_token(MSH_PROMPT).type != NEWLINE_TOKEN)
		{
		}
		ft_putchar_fd('\n', STDERR_FILENO);
		g_signal = 0;
		root = parse(PROGRAM, grammar, NULL);
	}
	return (root);
}
