/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:56:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/28 17:17:15 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * @brief Represents a node in a linkded list for storing process IDs 
*/
typedef struct s_pid_node
{
	/**< Process ID value */
	unsigned int		pid;
	/**< Pointer to the next node in the linked list */
	struct s_pid_node	*next;
}	t_pid_node;

/**
 * @brief Creates a new node of type t_pid_node and initializes it wit pid
 * @param pid A value that the node's pid member is initialized with
 * @return A pointer to the newly created node
*/
t_pid_node	*create_node(const unsigned int pid);

/**
 * @brief Creates a new node of type t_pid_node and 
 * 	initializes it with default values:
 *	- pid = 0
 *	- next = NULL
 * @return	A pointer to the newly created node. If memory allocation fails \
 * the program exits with EXIT_FAILURE and doesn't return 
*/
t_pid_node	*add_node(t_pid_node *head, t_pid_node *pid_node);

/**
 * @brief The memory occupied by the linked list of t_pid_node type
 * @param head A pointer to the head of the linked list
*/
void		free_pid_list (t_pid_node *head);
