/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:21:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/29 22:23:39 by akeryan          ###   ########.fr       */
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
	int	state;

	while (1)
	{
		data->root = build_tree(grammar, NULL);
		//print_tree(data->root, 0);
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
		state = program(data->root, data);
		printf("state from program(): %d\n", state);
		clean_tree(data->root);
		if (state == 1)
		{
			printf("BREAK\n");
			break ;
		}
	}
	return (EXIT_SUCCESS);
}

int	main(void)
{
	t_grammar	grammar;
	t_data		data;

	if (setup_sigs() < 0)
	{
		perror("setup signals");
		return (EXIT_FAILURE);
	}
	init_data(&data);
	if (handle_shlvl(&data.env) < 0)
		return (EXIT_FAILURE);
	grammar = setup_grammar();
	run(&grammar, &data);
	clean_dblptr(data.env);
	return (data.exit_status);
}
