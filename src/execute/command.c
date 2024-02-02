/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/02 11:00:41 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "node.h"
#include "execute.h"
#include "word_list.h"
#include "libft.h"
#include "error.h"

static int ft_execve(char *cmd_name, char **argv);
static char	**list_to_array(const t_word_node *head);

void	command(const t_node *node, t_data * const d)
{
	t_word_node	*args_list;
	t_pid_node	*pid_node;
	char		**argv;

	pid_node = new_pid();
	pid_node->pid = fork();
	if (pid_node->pid == -1)
		ft_printf(2, "%s\n", strerror(errno));
	else if (pid_node->pid == 0)
	{
		prefix(node->left);
		suffix(node->right, args_list);
		argv = list_to_array(args_list);
		free_word_list(args_list);
		args_list = NULL;
		ft_execve(node->word, argv);
		free_split(argv);
	}
	else
		add_pid_front(d->pid_list, pid_node);
}

/**
 * @brief Executes command with execve system utility
 * @param cmd_name Name of the command to be executed
 * @param argv Arguments of the command
*/
static int ft_execve(char *cmd_name, char **argv)
{
	char	*path;

	if (!ft_strchr(cmd_name, '/'))
	{
		path = get_cmd_path(cmd_name);
		if (!path)
		{
			ft_printf(2, "%s: %s: %s\n", MSH_NAME, cmd_name, NO_CMD);//STOPPED HERE
			return (-1);
		}
	}
	if(execve(cmd_name, argv, NULL) == -1)
		if (errno == EFAULT)
			ft_printf(2, "%s\n", strerror(errno));
		else if (errno == ENOENT)
			ft_printf(2, "%s: %s\n", cmd_name, strerror(errno));
	ft_printf(2, "Error: execve in execve_cmd: %s\n", strerror(errno));
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
