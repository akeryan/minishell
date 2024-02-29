/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_command_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/29 15:40:04 by akeryan          ###   ########.fr       */
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
#include "free.h"
#include "expansion.h"
#include "builtins.h"
#include "main_utils.h"

int	run_exit(char **argv, t_data *data)
{
	data->exit_status = ft_exit(argv);
	if (data->exit_status == 1)
		return (1);
	else
		return (0);
}

int	run_builtin(char *cmd, char **argv, t_data *data)
{
	if (cmd)
	{
		if (ft_strcmp(cmd, "echo") == 0)
			return (echo((const char **)argv));
		if (ft_strcmp(cmd, "cd") == 0)
			return (cd((const char **)argv, &data->env));
		if (ft_strcmp(cmd, "pwd") == 0)
			return (pwd());
		if (ft_strcmp(cmd, "export") == 0)
			return (ft_export(argv, &data->env));
		if (ft_strcmp(cmd, "unset") == 0)
			return (unset(argv, data->env));
		if (ft_strcmp(cmd, "env") == 0)
			return (env(argv, data->env));
	}
	return (-100);
}

int	get_cmd_from_args(char ***argv, t_node *node)
{
	char	**tmp;
	char	*tmp_word;

	if (*argv[1] == NULL)
		return (0);
	else
	{
		tmp_word = ft_strdup(*argv[1]);
		if (tmp_word == NULL)
			return (-1);
		free(node->word);
		node->word = tmp_word;
		tmp = ft_strdup2(*argv + 1);
		free_split(*argv);
		*argv = tmp;
		if (*argv == NULL)
		{
			ft_printf(2, "failed to malloc in ft_strdup2(): %s\n", \
				strerror(errno));
			return (-1);
		}
	}
	return (0);
}
