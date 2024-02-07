/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:21:48 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/07 14:48:50 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "tokens.h"
#include "minishell.h"
#include "readline/readline.h"
#include "readline/history.h"
#include <errno.h>

static size_t	token_len(const char *cursor, t_token_type type)
{
	if (type == EOF_TOKEN)
		return (0);
	else if (type == DLESS || type == DGREAT)
		return (2);
	else if (type != WORD)
		return (1);
	return (word_len(cursor));
}

//Order of check is important. Do the longest strings first.
static t_token	define_token(char *cursor)
{
	t_token	token;

	token.type = typify_token(cursor);
	token.slice.location = cursor;
	token.slice.length = token_len(cursor, token.type);
	return (token);
}

static t_token	process_token(int consume)
{
	static char		*line;
	static char		*cursor;
	static t_token	token;

	if (token.type == EOF_TOKEN)
		return (token);
	if (!line)
	{
		line = readline(MSH_PROMPT);
		if (line)
			add_history(line);
		errno = 0;
		cursor = line;
	}
	while (cursor && (*cursor == ' ' || *cursor == '\t'))
		cursor++;
	token = define_token(cursor);
	if (consume > 0 && cursor && *cursor != '\0')
		cursor += token.slice.length;
	else if (consume > 0 && cursor && *cursor == '\0')
	{
		ft_free((void **) &line);
		cursor = NULL;
	}
	return (token);
}

/**
 * @brief Peek a current token from STDIN
 * @brief Peeks a current token from readline() function
 * @return Returns a recognised token of type t_token
*/
t_token	peek_token(void)
{
	return (process_token(0));
}

/**
 * @brief Consume a current token from STDIN
 * @brief Consumes a current token from readline() function and moves the
 * cursor to the next token.
 * @return Returns a recognised token of type t_token
*/
t_token	consume_token(void)
{
	return (process_token(1));
}
