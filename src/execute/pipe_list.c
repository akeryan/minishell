/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:07:55 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/04 20:52:02 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "error_handling.h"
#include "pipe_list.h"

/**
 * @brief	Creates a new node of type t_pipe_node and 
 * 	initializes its members as follows:
 *	- fd: calls pipe function by passing fd as an argument
 *	- next: assigns NULL
 *	- prev: assigns NULL
 * @return	A pointer to the newly created node. 
 * @return	NULL - If memory allocation or pipe fail
*/
t_pipe_node	*new_pipe(void)
{
	t_pipe_node	*new_node;

	errno = 0;
	new_node = (t_pipe_node *)malloc(sizeof(t_pipe_node));
	if (new_node == NULL)
	{
		malloc_error_msg();
		return (NULL);
	}
	if (pipe(new_node->fd) == -1)
	{
		ft_printf(2, "%s: %s\n", MSH_NAME, strerror(errno));
		return (NULL);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * @brief Adds node to the beginning of the list
 * @param head Pointer to the first node of the list
 * @param node Pointer to the node that needs to be added to the list
*/
void	add_pipe_front(t_pipe_node **head, t_pipe_node *node)
{
	if (head)
	{
		if (*head && node)
		{
			node->next = *head;
			(*head)->prev = node;
		}
		*head = node;
	}
}

/**
 * @brief The memory occupied by the linked list of t_pipe_node type
 * @param head A pointer to the head of the linked list
*/
void	free_pipe_list(t_pipe_node *head)
{
	t_pipe_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
