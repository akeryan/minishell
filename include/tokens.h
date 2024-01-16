/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:27:29 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/16 11:11:21 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include <unistd.h>
# include "minishell.h"

/** Operator symbols */
# define OP_PIPE "|"
# define OP_HERE_DOC "<<"
# define OP_APP_REDIR ">>"
# define OP_IN_REDIR "<"
# define OP_OUT_REDIR ">"
# define OP_EXPAN "$"
# define OP_DOUBLE_QUOTE "\""
# define OP_SINGLE_QUOTE "\'"
# define OP_SPACE_CHAR ' '
# define OP_TAB_CHAR '\t'

/** Type of a token */
typedef enum e_token_type
{
	ERROR_TOKEN = -1,
	END_TOKEN = 0,
	PIPE_TOKEN = 1,
	HERE_DOC_TOKEN = 2,
	APP_REDIR_TOKEN = 3,
	IN_REDIR_TOKEN = 4,
	OUT_REDIR_TOKEN = 5,
	EXPAN_TOKEN = 6,
	DOUBLE_QUOTE_TOKEN = 7,
	SINGLE_QUOTE_TOKEN = 8,
	WORD_TOKEN = 9,
	BLANK_TOKEN = 10
}	t_token_type;

/** A slice of a string */
typedef struct s_slice
{
	char	*location;
	size_t	length;
}	t_slice;

/** A Token to be parsed */
typedef struct s_token
{
	t_token_type	type;
	t_slice			slice;
}	t_token;

t_token	get_next_token(t_line *line);

#endif
