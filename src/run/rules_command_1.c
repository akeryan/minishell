/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_command_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:01:50 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/01 20:57:51 by akeryan          ###   ########.fr       */
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

void	ft_cleaner(t_data *d, t_word_node *arglist, char **argv, int status) 
{
	clean_tree(d->root);
	clean_dblptr(argv);
	free_word_list(arglist);
	clean_dblptr(d->env);
	exit(status);
}

static void	ft_execve(char *cmd_name, char **argv, t_data *d, t_word_node *arg_lst)
{
	char				*path;
	char				*tmp;
	int					status;

	status = EXIT_SUCCESS;
	if (ft_strchr(cmd_name, '/'))
	{
		path = ft_strdup(cmd_name);
		tmp = ft_strdup(ft_strrchr(argv[0], '/') + 1);
		if (tmp == NULL)
			panic_malloc();
		ft_free((void **)&argv[0]);
		argv[0] = tmp;
	}
	else
		path = get_cmd_path(cmd_name, d->env);
	ft_process_signals();
	if (execve(path, argv, d->env) == -1)
		status = execve_error_msg(path, cmd_name);
	ft_free((void **)&path);
	ft_cleaner(d, arg_lst, argv, status);
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
	int			state;

	if (!node)
		return (EXIT_FAILURE);
	args_list = NULL;
	argv = NULL;
	prefix(node->left, data);
	suffix(node->right, &args_list, data);
	apply_expansions(&node->word, data);
	argv = list_to_array(args_list, node->word);
	if (argv == NULL)
		return (EXIT_FAILURE);
	if (node->word && ft_strcmp(node->word, "") == 0)
	{
		if (get_cmd_from_args(&argv, node) == -1)
			return (EXIT_FAILURE);
		else
		{
			data->exit_status = 0;
			return (EXIT_SUCCESS);
		}
	}
	if (ft_strcmp(node->word, "exit") == 0)
	{
		state = run_exit(argv, data);
		//printf("state from run_exit(): %d\n", state);
	}
	else
	{
		state = run_builtin(node->word, argv, data);
		data->exit_status = state;
	}
	if (state == -100 && node->word)
		ft_execve(node->word, argv, data, args_list);
	//return(state);
	return (free_word_list(args_list), clean_dblptr(argv), state);
}
