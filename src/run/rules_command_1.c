/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_command_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:01:50 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/29 00:12:33 by akeryan          ###   ########.fr       */
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

static void	ft_process_signals(void)
{
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		return ;
}

/**
 * @brief Executes command with execve system utility
 * @param cmd_name Name of the command to be executed
 * @param argv Arguments of the command
*/
static void	ft_execve(char *cmd_name, char **argv, char **envp)
{
	char				*path;
	char				*tmp;
	int					status;

	status = EXIT_SUCCESS;
	if (ft_strchr(cmd_name, '/'))
	{
		path = cmd_name;
		tmp = ft_strdup(ft_strrchr(argv[0], '/') + 1);
		if (tmp == NULL)
			panic_malloc();
		free(argv[0]);
		argv[0] = tmp;
	}
	else
		path = get_cmd_path(cmd_name, envp);
	if (path != NULL)
	{
		ft_process_signals();
		if (execve(path, argv, envp) == -1)
			status = execve_error_msg(path);
		free(path);
		exit(status);
	}
	ft_printf(2, "%s: %s: %s\n", MSH_NAME, cmd_name, "command not found");
	exit(127);
}

/**
 * @brief Implements 'command' node of the parsing tree
 * @param node Pointer to the COMMAND node
 * @param d Pointer to the t_data structure
 * @return 0: Successful execution;
 * @return -1: Execution failed;
*/
int	command(t_node *const node, t_data *data)
{
	t_word_node	*args_list;
	char		**argv;
	int			builtin_status;

	if (!node)
		return (EXIT_FAILURE);
	args_list = NULL;
	argv = NULL;
	prefix(node->left, data);
	suffix(node->right, &args_list, data);
	apply_expansions(&node->word, data);
	argv = list_to_array(args_list, node->word);
	if (argv == NULL)
	{
		ft_printf(2, "failed to malloc in list_to_array(): %s\n", \
			strerror(errno));
		return (EXIT_FAILURE);
	}
	if (node->word && ft_strcmp(node->word, "") == 0)
		if (get_cmd_from_args(&argv, node) == -1)
			return (EXIT_FAILURE);
	builtin_status = run_builtin(node->word, argv, data);
	if (builtin_status == -100 && node->word)
		ft_execve(node->word, argv, data->env);
	return (free_word_list(args_list), free_split(argv), builtin_status);
}
