/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/04 20:50:28 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "rules.h"
#include "execute.h"
#include "word_list.h"
#include "libft.h"
#include "error_handling.h"

static int	ft_execve(char *cmd_name, char **argv);
static char	**list_to_array(const t_word_node *head);
static int	child_process(const t_node *const node, t_word_node *args_list,
				char **argv, t_pid_node *const pid_node);

/**
 * @brief Implements 'command' node of the parsing tree
 * @param node Pointer to the COMMAND node
 * @param d Pointer to the t_data structure
 * @return 0: Successful execution;
 * @return -1: Execution failed;
*/
int	command(const t_node *const node, t_data *const d)
{
	t_word_node	*args_list;
	t_pid_node	*pid_node;
	char		**argv;

	args_list = NULL;
	pid_node = NULL;
	argv = NULL;
	pid_node = new_pid();
	if (pid_node == NULL)
		return (-1);
	pid_node->pid = fork();
	if (pid_node->pid == -1)
	{
		perror("fork (command): ");
		return (-1);
	}
	if (pid_node->pid == 0)
		if (child_process(node, args_list, argv, pid_node) == -1)
			return (-1);
	else
		add_pid_front(d->pid_list, pid_node);
	return (0);
}

static int	child_process(	const t_node *const node,
							t_word_node *args_list,
							char **argv,
							t_pid_node *const pid_node )
{
	if (prefix(node->left) == -1)
		return (-1);
	if (suffix(node->right, args_list) == -1)
		return (-1);
	if (args_list != NULL)
		argv = list_to_array(args_list);
	free_word_list(args_list);
	args_list = NULL;
	ft_execve(node->word, argv);
	free_pid_list(pid_node);
	free_split(argv);
	return (-1);
}

/**
 * @brief Executes command with execve system utility
 * @param cmd_name Name of the command to be executed
 * @param argv Arguments of the command
*/
static int	ft_execve(char *cmd_name, char **argv)
{
	char	*path;

	if (!ft_strchr(cmd_name, '/'))
		path = get_cmd_path(cmd_name);
	else
		path = cmd_name;
	if (execve(path, argv, NULL) == -1)
		execve_error_msg(path);
	free(path);
	return (-1);
}

/**
 * @brief Converts the t_word_node list to an array of strings
 * @param head A pointer to the first node of the list 
 * @return A pointer to the array of strings
*/
static char	**list_to_array(const t_word_node *head)
{
	char		**arr;
	int			len;
	int			i;

	len = word_list_len(head);
	arr = (char **)malloc((len + 1) * sizeof(char *));
	if (arr == NULL)
	{
		perror("malloc (list_to_array): ");
		return (NULL);
	}
	i = 0;
	while (head)
	{
		arr[i] = ft_strdup(head->word);
		if (arr[i] == NULL)
		{
			while (--i >= 0)
				free(arr[i]);
			return (NULL);
		}
		head = head->next;
		i++;
	}
	return (arr[i] = NULL, arr);
}
