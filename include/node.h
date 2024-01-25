/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:14:32 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/25 15:42:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "tokens.h"

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
