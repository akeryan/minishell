/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/21 20:45:34 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "rules.h"
#include "word_list.h"
#include "libft.h"
#include "error_handling.h"
#include "free.h"
#include "expansion.h"
#include "builtins.h"

/**
 * @brief Executes command with execve system utility
 * @param cmd_name Name of the command to be executed
 * @param argv Arguments of the command
*/
static void	ft_execve(char *cmd_name, char **argv)
{
	char	*path;

	if (!ft_strchr(cmd_name, '/'))
	{
		path = get_cmd_path(cmd_name);
		if (!path)
			path_error_msg(cmd_name);
	}
	else
		path = cmd_name;
	if (execve(path, argv, NULL) == -1)
		path_error_msg(path);//STOPPED HERE 
		//explore all the possible values of errno that occure when execve returns -1
		//currently it executes path_error_msg, which outputs path related errors...
	free(path);
	exit(EXIT_FAILURE);
}

/**
 * @brief Converts the t_word_node list to an array of strings
 * @param head A pointer to the first node of the list 
 * @return A pointer to the array of strings
*/
static char	**list_to_array(t_word_node *head, char *cmd_name)
{
	char		**argv;
	int			len;
	int			i;

	len = word_list_len(head);
	argv = (char **)malloc((len + 2) * sizeof(char *));
	if (argv == NULL)
	{
		perror("malloc (list_to_array): ");
		return (NULL);
	}
	i = 1;
	while (head)
	{
		argv[i] = ft_strdup(head->word);
		if (argv[i] == NULL)
		{
			while (--i >= 0)
				free(argv[i]);
			return (NULL);
		}
		head = head->next;
		i++;
	}
	return (argv[0] = cmd_name, argv[i] = NULL, argv);
}

static int	run_builtin(char *cmd, char **argv, char ***envp)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (echo((const char **)argv));
	if (ft_strcmp(cmd, "cd") == 0)
		return (cd((const char **)argv, envp));
	if (ft_strcmp(cmd, "pwd") == 0)
		return (pwd());
	if (ft_strcmp(cmd, "export") == 0)
		return (ft_export(argv, envp));
	if (ft_strcmp(cmd, "unset") == 0)
		return (unset(argv, *envp));
	if (ft_strcmp(cmd, "env") == 0)
		return (env(argv, *envp));
	if (ft_strcmp(cmd, "exit") == 0)
		return (ft_exit(argv));
	return (42);
}

/**
 * @brief Implements 'command' node of the parsing tree
 * @param node Pointer to the COMMAND node
 * @param d Pointer to the t_data structure
 * @return 0: Successful execution;
 * @return -1: Execution failed;
*/
void	command(t_node *const node, t_data *data)
{
	t_word_node	*args_list;
	char		**argv;
	int			builtin_status;

	if (!node)
		return ;
	args_list = NULL;
	argv = NULL;
	prefix(node->left, data);
	suffix(node->right, &args_list, data);
	argv = list_to_array(args_list, node->word);
	apply_expansions(&node->word, data);
	builtin_status = run_builtin(node->word, argv, &data->env);
	if (builtin_status == 42)
		ft_execve(node->word, argv);
	free_word_list(args_list);
	free_split(argv);
	exit(builtin_status);
}
