/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:14:32 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/25 14:32:08 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
#define NODE_H

#include "tokens.h"

typedef enum e_node_type
{
	PROGRAM = 0, 
	PIPELINE = 1,
	COMMAND = 2,
	PREFIX = 4,
	SUFIX = 5,
	IO_REDIR = 6,
	NEWLINE_LIST = 12
} t_node_type;

typedef struct s_node
{
	t_node_type		node_type;
	char			*word;
	t_token_type	token_type;
	struct s_node	*left;
	struct s_node	*right;
} t_node;

#endif