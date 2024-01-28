/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:59:14 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/28 19:54:39 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include "pid_list.h"

/**
 * @brief Creates a new node of type t_pid_node and 
 * 	initializes it with default values:
 *	pid = 0, next = NULL
 * @return	A pointer to the newly created node. If memory allocation fails \
 * the program exits with EXIT_FAILURE and doesn't return 
*/
static t_pid_node	*new_node(void)
{
	t_pid_node	*new_node;

	new_node = (t_pid_node *)malloc(sizeof(t_pid_node));
	if (new_node == NULL)
	{
		//ft_printf(2, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	new_node->pid = 0;
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
t_pid_node	*add_node(t_pid_node *head, t_pid_node *node)
{
	if (node == NULL)
		return (head);
	if (head == NULL)
		return (node);
	node->next = head;
	return (node);
}

/**
 * @brief The memory occupied by the linked list of t_pid_node type
 * @param head A pointer to the head of the linked list
*/
void	free_pid_list(t_pid_node *head)
{
	t_pid_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
