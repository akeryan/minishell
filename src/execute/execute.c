/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:27:16 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/07 21:33:22 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "execute.h"

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
		add_pipe_front(&data->pipe_list, pipe_node);
		current = current->right;
	}
	return (0);
}
