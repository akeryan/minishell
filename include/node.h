/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:14:32 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/24 19:02:50 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
#define NODE_H

#include "tokens.h"

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

typedef char*	t_word_value;
typedef t_node*	t_cmd_name_value;
typedef t_node*	t_cmd_word_value;
typedef t_node*	t_filename_value;
typedef char*	t_dless_value;
typedef t_node*	t_here_end_value;

typedef struct s_node
{
	t_node_type		type;
	t_node_value	data;
} t_node;

typedef struct s_pipeline_value
{
	t_node	*cmd;
	t_node	*next;
} t_pipeline_value;

typedef struct s_cmd_value
{
	t_node	*prefix;
	t_node	*word;
	t_node	*sufix;
	t_node	*cmd_name;
	t_node	*cmd_word;
} t_cmd_value;

typedef struct s_prefix_value
{
	t_node	*io_redir;
	t_node	*next;
} t_prefix_value;

typedef struct s_sufix_value
{
	t_node	*io_redir;
	t_node	*next;
	t_node	*word;
} t_sufix_value;

typedef struct s_redir_value
{
	t_node	*io_file;
	t_node	*io_here;
} t_redir_value;

typedef struct s_io_file_value
{
	t_node	*io_op;
	t_node	*filename;
} t_io_file_value;

typedef struct s_io_here_value
{
	t_node	*here_end;
	t_node	*dless;
}	t_io_here_value;

typedef union u_node_value
{
	t_pipeline_value	pipeline;
	t_cmd_value			cmd;
	t_cmd_name_value	cmd_name;
	t_word_value		word;	
	t_prefix_value		prefix;
	t_sufix_value		sufix;
	t_redir_value		io_redir;
	t_io_file_value		io_file;
	t_filename_value	filename;
	t_dless_value		dless;
	t_here_end_value	here_end;
} t_node_value;

#endif