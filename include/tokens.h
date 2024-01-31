/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:27:29 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/31 15:39:29 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENS_H
# define TOKENS_H

# include <unistd.h>

/** Operator symbols. Keep them as strings */
# define OP_PIPE "|"
# define OP_DLESS "<<"
# define OP_DGREAT ">>"
# define OP_LESS "<"
# define OP_GREAT ">"

/** Type of a token */
typedef enum e_token_type
{
	EOF_TOKEN = -1,
	NEWLINE_TOKEN = 0,
	PIPE = 1,
	DLESS = 2,
	DGREAT = 3,
	LESS = 4,
	GREAT = 5,
	WORD = 6,
	EMPTY = 7
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

t_token	peek_token(void);
t_token	consume_token(void);

#endif
