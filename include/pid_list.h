/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:56:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/07 21:34:39 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PID_LIST_H
# define PID_LIST_H

// ---------------- DATA STRUCTURES -----------------------
/**
 * @brief Represents a node in a linkded list for storing process IDs 
*/
typedef struct s_pid_node
{
	int					pid;
	struct s_pid_node	*next;
}	t_pid_node;

// ---------------- PROTOTYPES ----------------------------
/**
 * @brief Creates a new node of type t_pid_node 
 * @return	A pointer to the newly created node. If memory allocation fails
 * the program exits with EXIT_FAILURE and doesn't return 
*/
t_pid_node	*new_pid(void);

/**
 * @brief Adds node to the beginning of the list
 * @param head Pointer to the first node of the list
 * @param node Pointer to the node that needs to be added to the list
*/
void		add_pid_front(t_pid_node **head, t_pid_node *pid_node);

/**
 * @brief The memory occupied by the linked list of t_pid_node type
 * @param head A pointer to the head of the linked list
*/
int			free_pid_list(t_pid_node *head);

#endif