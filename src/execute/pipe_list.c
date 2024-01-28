/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:07:55 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/28 19:58:21 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include "pipe_list.h"

/**
 * @brief Creates a new node of type t_pipe_node and 
 * 	initializes it with default values:
 *	- fd = [0, 0]
 *	- next = NULL
 * @return	A pointer to the newly created node. If memory allocation fails \
 * the program exits with EXIT_FAILURE and doesn't return 
*/
t_pipe_node	*new_pipe(void)
{
	t_pipe_node	*new_node;

	new_node = (t_pipe_node *)malloc(sizeof(t_pipe_node));
	if (new_node == NULL)
	{
		//ft_printf(2, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	new_node->fd[0] = 0;
	new_node->fd[1] = 0;
	new_node->next = NULL;
	return (new_node);
}

/**
 * @brief Adds node to the beginning of the list
 * 	The function is used the following way:
 * 		head = add_node(head, new_node);
 * @param head Pointer to the first node of the list
 * @param node Pointer to the node that needs to be added to the list
 * @return Pointer to the new 'head' of the list
 * Beaware of passing uninitilized arguments to the function
*/
t_pipe_node	*add_pipe(t_pipe_node *head, t_pipe_node *node)
{
	if (node == NULL)
		return (head);
	if (head == NULL)
		return (node);
	node->next = head;
	return (node);
}
