/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:59:34 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/04 12:09:30 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

#include "pipe_list.h"
#include "pid_list.h"
#include "tokens.h"

typedef struct s_data
{
	t_pid_node	*pid_list;
	t_pipe_node	*pipe_list;
}	t_data;

/** Types of nodes */
typedef enum e_node_type
{
	PROGRAM = 0,
	PIPELINE = 1,
	COMMAND = 2,
	PREFIX = 3,
	SUFFIX = 4,
	IO_REDIR = 5,
	NEWLINE_LIST = 6
}	t_node_type;

/**
 * Covers architectures of all types of nodes from e_node_type
 * See the 'Grammar' document to distinguish between node structures
 * e.g. 'COMMAND' node uitlizes the following attributes
 * - 'left' for 'prefix' node
 * - 'word' for 'command name'
 * - 'right' for 'suffix' node
 * - the rest of the attributes are left uninitialized;
*/
typedef struct s_node
{
	char			*word;
	t_node_type		node_type;
	t_token_type	redir_type;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

#endif