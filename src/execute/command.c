/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/30 14:00:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "node.h"
#include "execute.h"
#include "word_list.h"
#include "libft.h"

static void	close_pipes(const t_pipe_node *head);
static char	**list_to_array(const t_word_node *head);

void	command(const t_node *node, t_data * const d)
{
	t_word_node	*args_list;
	t_pid_node	*pid_node;
	char		**argv;

	pid_node = new_pid();
	pid_node->pid = fork();
	if (pid_node->pid == -1)
		//ft_printf(2, "%s\n", strerror(errno));
	add_pid_front(d->pid_list, pid_node);
	if (pid_node->pid == 0)
	{
		prefix(node->left);
		suffix(node->right, args_list);
		close_pipes(d->pid_list);
		argv = list_to_array(args_list);
		free_word_list(args_list);
		args_list = NULL;
		ft_execve(node->word, argv, d);//I'VE STOPPED HERE
	}
}

/**
 * @brief Converts the t_word_node list to an array of strings
 * @param head A pointer to the first node of the list 
 * @return A pointer to the array of strings
*/
static char	**list_to_array(const t_word_node *head)
{
	char 		**arr;
	int			len;
	int			i;

	len = word_list_len(head);
	arr = (char **)malloc((len + 1) * sizeof(char *));
	i = 0;
	while (head)
	{
		arr[i] = ft_strdup(head->word);
		head = head->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

/**
 * @brief Closes all the listed pipes
 * @param head The head of the list
*/
static void	close_pipes(const t_pipe_node *head) 
{
	while (head)
	{
		close(head->fd[0]);
		close(head->fd[1]);	
		head = head->next;
	}
}

/**
 * @brief Executes command with execve system utility
 * @param cmd_name Name of the command to be executed
 * @param argv Arguments of the command
 * @param d->path Full path to the command
 * @param d->env Environmental variable of the parent process
*/
void ft_execve(char *cmd_name, char **argv, t_data *d)
{
	d->path = get_cmd_path(cmd_name, d->env);
	error_check(d->path, "get_cmd_path() failed", PTR);
	execve(d->path, argv, d->env);
	ft_printf(2, "Error: execve in execve_cmd: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}
