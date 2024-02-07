/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:59:14 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/07 17:18:45 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "pid_list.h"
#include "error_handling.h"

/**
 * @brief Creates a new node of type t_pid_node and 
 * 	initializes it with default values:
 *	pid = 0, next = NULL
 * @return	A pointer to the newly created node. If memory allocation fails \
 * the program exits with EXIT_FAILURE and doesn't return 
*/
t_pid_node	*new_pid(void)
{
	t_pid_node	*new_node;

	errno = 0;
	new_node = (t_pid_node *)malloc(sizeof(t_pid_node));
	if (new_node == NULL)
	{
		perror("malloc: ");
		return (NULL);
	}
	new_node->pid = 0;
	new_node->next = NULL;
	return (new_node);
}

/**
 * @brief Adds node to the beginning of the list
 * @param head Pointer to the first node of the list
 * @param node Pointer to the node that needs to be added to the list
*/
void	add_pid_front(t_pid_node **head, t_pid_node *node)
{
	if (head)
	{
		if (*head && node)
			node->next = *head;
		*head = node;
	}
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
