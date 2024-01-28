/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:03:48 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/28 20:00:11 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_LIST_H
# define PIPE_LIST_H

/**
 * @brief Represents a node in a linked list for storing pipe's file fescriptors
*/
typedef struct s_pipe_node
{
	int					fd[2];
	struct s_pipe_node	*next;
}	t_pipe_node;

/**
 * @brief Creates a new node of type t_pipe_node and 
 * 	initializes it with default values:
 *	- fd = [0, 0]
 *	- next = NULL
 * @return	A pointer to the newly created node. If memory allocation fails \
 * the program exits with EXIT_FAILURE and doesn't return 
*/
t_pipe_node	*new_pipe(void);

/**
 * @brief Adds node to the beginning of the list
 * 	The function is used the following way:
 * 		head = add_node(head, new_node);
 * @param head Pointer to the first node of the list
 * @param node Pointer to the node that needs to be added to the list
 * @return Pointer to the new 'head' of the list
 * Beaware of passing uninitilized arguments to the function
*/
t_pipe_node	*add_pipe(t_pipe_node *head, t_pipe_node *node);

#endif