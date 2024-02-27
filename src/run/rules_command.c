/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/28 02:07:57 by akeryan          ###   ########.fr       */
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

/**
 * @brief Executes command with execve system utility
 * @param cmd_name Name of the command to be executed
 * @param argv Arguments of the command
*/
static void	ft_execve(char *cmd_name, char **argv, char **envp)
{
	struct sigaction	s_sint;
	char				*path;
	char				*tmp;

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
	s_sint.__sigaction_u.__sa_handler = SIG_DFL;
	s_sint.sa_flags = 0;
	s_sint.sa_mask = 0;
	if (sigaction(SIGQUIT, &s_sint, NULL) < 0)
		return ;
	if (execve(path, argv, envp) == -1)
		cmd_error_msg(cmd_name);//STOPPED HERE 
		//explore all the possible values of errno that occure when execve returns -1
		//currently it executes path_error_msg, which outputs path related errors...
	free(path);
	exit(EXIT_FAILURE);
}


static int	run_exit(char **argv, t_data *data)
{
	int	status;

	status = ft_exit(argv);
	if (status != 1)
		exit (status);
	else
	{
		data->exit_status = 1;
		return (EXIT_FAILURE);
	}
	return (status);
}

static int	run_builtin(char *cmd, char **argv, t_data *data)
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
		if (ft_strcmp(cmd, "exit") == 0)
			return (run_exit(argv, data));
	}
	return (-100);
}

static int	get_cmd_from_args(char ***argv, t_node *node)
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
