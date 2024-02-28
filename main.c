/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:21:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/29 00:53:50 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <errno.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "minishell.h"
#include "parse.h"
#include "rules.h"
#include "main_utils.h"
#include "print_tree.h"

void	print_tree(t_node *node, int level);

void	init_data(t_data *data)
{
	extern char	**environ;

	data->env = ft_copy_strv((const char **)environ);
	data->exit_status = 0;
	data->dbl_dollar = getpid();
	data->less_fd = -1;
	data->great_fd = -1;
	data->root = NULL;
}

static int	run(t_grammar *grammar, t_data *data)
{
	while (1)
	{
		data->root = build_tree(grammar, NULL);
		if (errno != 0)
			perror("ERRNO");
		if (!data->root)
		{
			if (peek_token(NULL).type == EOF_TOKEN)
			{
				printf(EXIT_MSG);
				return (EXIT_SUCCESS);
			}
			else
			{
				ft_printf(2, "minishell: syntax error near unexpected token \
					'%s'\n", token_type_to_a(peek_token(NULL).type));
				while (consume_token(NULL).type != NEWLINE_TOKEN)
					;
			}
		}
		program(data->root, data);
		clean_tree(data->root);
	}
}

int	main(void)
{
	t_grammar	grammar;
	t_data		data;
	int			status;

	if (setup_sigs() < 0)
	{
		perror("setup signals");
		return (EXIT_FAILURE);
	}
	init_data(&data);
	if (handle_shlvl(&data.env) < 0)
		return (EXIT_FAILURE);
	grammar = setup_grammar();
	status = run(&grammar, &data);
	return (status);
}
