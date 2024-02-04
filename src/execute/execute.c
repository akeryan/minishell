/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:27:16 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/04 20:52:55 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execute.h"
#include "word_list.h"
#include "ft_printf.h"

/**
 * @brief Initializes the t_data structure variable
 * @param data Pointer to a t_data variable 
 * @return 0 - Successful execution
 * @return 1 - data argument is empty
*/
int	init_data(t_data *data)
{
	if (!data)
		return (1);
	data->pid_list = NULL;
	data->pipe_list = NULL;
	return (0);
}

/**
 * @brief Malloced memory by t_data variable
 * @param data Pointer to t_data variable
 * @return 0 - Successful execution
 * @return 1 - Argument is empty
*/
int	free_data(t_data *data)
{
	if (!data)
		return (1);
	if (data->pid_list)
		free_pid_list(data->pid_list);
	if (data->pipe_list)
		free_pipe_list(data->pipe_list);
	return (0);
}

/**
 * @brief Explores the parser tree and creates pipes if present
 * @param head Pointer to the head of the tree
 * @param data Pointer to a t_data variable
 * @return 0 - if the pipes were created successfully;
 * @return 1 - if head argument is a NULL;
 * @return -1 - if pipe() failed. 'data' is freed before returning;
*/
int	create_pipes(t_node *head, t_data *data)
{
	t_pipe_node	*pipe_node;
	t_node		*current;

	if (head == NULL)
		return (1);
	current = head;
	if (!current->right)
		return (0);
	current = current->right;
	while (current->right)
	{
		pipe_node = new_pipe();
		if (pipe_node == NULL)
			return (-1);
		add_pipe_front(data->pipe_list, pipe);
		current = current->right;
	}
	return (0);
}
