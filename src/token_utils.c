/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:21:48 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/31 16:17:19 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "tokens.h"
#include "minishell.h"
#include "readline/readline.h"
#include "readline/history.h"

static size_t	token_len(const char *cursor, t_token_type type)
{
	char	delim;
	size_t	i;

	if (type == EOF_TOKEN)
		return (0);
	else if (type == NEWLINE_TOKEN || type == PIPE)
		return (1);
	else if (type == DLESS)
		return (ft_strlen(OP_DLESS));
	else if (type == DGREAT)
		return (ft_strlen(OP_DGREAT));
	else if (type == LESS)
		return (ft_strlen(OP_LESS));
	else if (type == GREAT)
		return (ft_strlen(OP_GREAT));
	delim = ' ';
	i = 1;
	if (*cursor == '\"' || *cursor == '\'')
		delim = *cursor;
	while (*(cursor + i) && *(cursor + i) != delim)
		i++;
	if (delim != ' ' && *(cursor + i))
		i++;
	return (i);
}

//Order of check is important. Do the longest strings first.
static t_token_type	typify_token(const char *cursor)
{
	if (!cursor)
		return (EOF_TOKEN);
	else if (*cursor == '\0')
		return (NEWLINE_TOKEN);
	else if (!ft_strncmp(cursor, OP_PIPE, ft_strlen(OP_PIPE)))
		return (PIPE);
	else if (!ft_strncmp(cursor, OP_DLESS, ft_strlen(OP_DLESS)))
		return (DLESS);
	else if (!ft_strncmp(cursor, OP_DGREAT, ft_strlen(OP_DGREAT)))
		return (DGREAT);
	else if (!ft_strncmp(cursor, OP_LESS, ft_strlen(OP_LESS)))
		return (LESS);
	else if (!ft_strncmp(cursor, OP_GREAT, ft_strlen(OP_GREAT)))
		return (GREAT);
	else
		return (WORD);
}

static t_token	process_token(int consume)
{
	static char	*line;
	static char	*cursor;
	t_token		token;

	if (!line || !cursor)
	{
		line = readline(MSH_PROMPT);
		add_history(line);
		cursor = line;
	}
	while (cursor && (*cursor == ' ' || *cursor == '\t'))
		cursor++;
	token.type = typify_token(cursor);
	token.slice.location = cursor;
	token.slice.length = token_len(cursor, token.type);
	if (consume > 0 && cursor && *cursor == '\0')
	{
		ft_free((void **) &line);
		cursor = NULL;
	}
	else if (consume > 0 && cursor && *cursor != '\0')
		cursor += token.slice.length;
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
