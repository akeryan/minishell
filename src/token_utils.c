/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:21:48 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/05 17:31:35 by dabdygal         ###   ########.fr       */
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
	char	delim;
	size_t	i;

	if (type == EOF_TOKEN)
		return (0);
	else if (type == NEWLINE_TOKEN || type == PIPE)
		return (1);
	else if (type == DLESS || type == DGREAT)
		return (2);
	else if (type == LESS)
		return (ft_strlen(OP_LESS));
	else if (type == GREAT)
		return (ft_strlen(OP_GREAT));
	delim = ' ';
	i = 0;
	while (*(cursor + i) && *(cursor + i) != delim)
	{
		if ((*(cursor + i) == '\"' || *(cursor + i) == '\'') && delim == ' ')
			delim = *(cursor + i);
		i++;
	}
	if (*(cursor + i) && delim != ' ')
		i++;
	return (i);
}

//Order of check is important. Do the longest strings first.
static t_token	define_token(char *cursor)
{
	t_token	token;

	if (!cursor)
		token.type = EOF_TOKEN;
	else if (*cursor == '\0')
		token.type = NEWLINE_TOKEN;
	else if (!ft_strncmp(cursor, OP_PIPE, ft_strlen(OP_PIPE)))
		token.type = PIPE;
	else if (!ft_strncmp(cursor, OP_DLESS, ft_strlen(OP_DLESS)))
		token.type = DLESS;
	else if (!ft_strncmp(cursor, OP_DGREAT, ft_strlen(OP_DGREAT)))
		token.type = DGREAT;
	else if (!ft_strncmp(cursor, OP_LESS, ft_strlen(OP_LESS)))
		token.type = LESS;
	else if (!ft_strncmp(cursor, OP_GREAT, ft_strlen(OP_GREAT)))
		token.type = GREAT;
	else
		token.type = WORD;
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
