/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:14:32 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/23 17:07:26 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
#define NODE_H

/** */
typedef enum e_node_type
{
	ERROR_NODE = -1,
	PIPELINE_NODE = 0,
	COMMAND_NODE = 1,
	NAME_NODE = 2,
	WORD_NODE = 3,
	PREFIX_NODE = 4,
	SUFIX_NODE = 5,
	IO_REDIR_NODE = 6,
	IO_FILE_NODE = 7,
	FILENAME_NODE = 8,
	IO_HERE_NODE = 9,
	HERE_END_NODE = 10,
	LINEBREAK_NODE = 11,
	NEWLINE_LIST_NODE = 12	
} t_node_type;

typedef struct s_node {
	t_node_type		type;
	t_node_value	data;
} t_node;

#endif