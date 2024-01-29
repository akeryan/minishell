/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:03:48 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/29 15:17:42 by akeryan          ###   ########.fr       */
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
 * @brief Creates a new node of type t_pipe_node 
 * @return	A pointer to the newly created node. If memory allocation fails
*/
t_pipe_node	*new_pipe(void);

/**
 * @brief Adds node to the beginning of the list
 * @param head Pointer to the first node of the list
 * @param node Pointer to the node that needs to be added to the list
*/
void		add_pipe_front(t_pipe_node *head, t_pipe_node *node);

/**
 * @brief Frees up the memory occupied by the linked list of t_pipe_node type
 * @param head A pointer to the head of the linked list
*/
void		free_pipe_list(t_pipe_node *head);

#endif