/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:59:34 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/27 20:50:49 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "pipe_list.h"
# include "pid_list.h"
# include "tokens.h"

typedef struct s_data
{
	char			**env;
	unsigned char	exit_status;
	pid_t			dbl_dollar;
	int				less_fd;
	int				great_fd;
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
	t_token_type	token_type;
	struct s_node	*left;
	struct s_node	*newl_ptr;
	struct s_node	*right;
}	t_node;

typedef struct s_tilde_vars
{
	char	*slash;
	char	*usr_name;
	char	*usrs_dir;
	char	*home_dir;
}	t_tilde_vars;

#endif