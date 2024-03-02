/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_command_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:52:23 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/02 14:56:29 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "signal.h"
#include "rules.h"
#include "word_list.h"
#include "libft.h"
#include "error_handling.h"
#include "expansion.h"
#include "builtins.h"
#include "main_utils.h"

int	cmd_func_1(char ***argv, t_node *node, t_data *data)
{
	if (node->word && ft_strcmp(node->word, "") == 0)
	{
		if (get_cmd_from_args(argv, node) == -1)
		{
			clean_dblptr(*argv);
			return (EXIT_FAILURE);
		}
		else
		{
			data->exit_status = 0;
			clean_dblptr(*argv);
			return (EXIT_SUCCESS);
		}
	}
	return (-1);
}

void	cmd_func_2(int *state, t_node *node, char **argv, t_data *data)
{
	*state = run_builtin(node->word, argv, data);
	data->exit_status = *state;
}
