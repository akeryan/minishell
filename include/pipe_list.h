/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:03:48 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/28 17:21:33 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Represents a node in a linked list for storing pipe's file fescriptors
*/
typedef struct s_pipe_node
{
	/**< An array that contains file descriptors for a pipe
	 * fd[0] is for reading from the pipe
	 * fd[1] is for writing from the pipe
	*/
	int					fd[2];
	/**< A Pointer to the next node in the linked list*/
	struct s_pipe_node	*next;
}	t_pipe_node;

	