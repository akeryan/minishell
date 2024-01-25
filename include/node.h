/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:14:32 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/25 14:38:24 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "tokens.h"

typedef enum e_node_type
{
	PROGRAM = 0,
	PIPELINE = 1,
	COMMAND = 2,
	PREFIX = 3,
	SUFIX = 4,
	IO_REDIR = 5,
	NEWLINE_LIST = 6
}	t_node_type;

typedef struct s_node
{
	char			*word;
	t_node_type		node_type;
	t_token_type	token_type;
	t_node			*left;
	t_node			*right;
}	t_node;

#endif