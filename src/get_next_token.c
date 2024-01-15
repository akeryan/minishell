/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:32:56 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/15 19:31:43 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "minishell.h"
#include "libft.h"

static t_token	detect_op(const t_line *line)
{
	t_token	token;

	token.type = END_TOKEN;
	token.slice.location = line->cursor;
	token.slice.length = 1;
	if (ft_strncmp(line->cursor, OP_PIPE, 1) == 0)
		token.type = PIPE_TOKEN;
	if (ft_strncmp(line->cursor, OP_IN_REDIR, 1) == 0)
		token.type = IN_REDIR_TOKEN;
	if (ft_strncmp(line->cursor, OP_OUT_REDIR, 1) == 0)
		token.type = OUT_REDIR_TOKEN;
	if (ft_strncmp(line->cursor, OP_EXPAN, 1) == 0)
		token.type = EXPAN_TOKEN;
	if (ft_strncmp(line->cursor, OP_DOUBLE_QUOTE, 1) == 0)
		token.type = DOUBLE_QUOTE_TOKEN;
	if (ft_strncmp(line->cursor, OP_SINGLE_QUOTE, 1) == 0)
		token.type = SINGLE_QUOTE_TOKEN;
	if (ft_strncmp(line->cursor, OP_HERE_DOC, 2) == 0)
		token.type = HERE_DOC_TOKEN;
	if (ft_strncmp(line->cursor, OP_APP_REDIR, 2) == 0)
		token.type = APP_REDIR_TOKEN;
	if (token.type == HERE_DOC_TOKEN || token.type == APP_REDIR_TOKEN)
		token.slice.length++;
	return (token);
}

static t_token	consume_token(t_line *line)
{
	t_token	token;

	token = detect_op(line);
	if (token.type == END_TOKEN)
	{
		token.type = WORD_TOKEN;
		token.slice.length = 0;
		while (*line->cursor && detect_op(line).type == END_TOKEN)
		{
			line->cursor++;
			token.slice.length++;
			if (*line->cursor == ' ' || *line->cursor == '\t')
				break ;
		}
	}
	else
		line->cursor += token.slice.length;
	return (token);
}

/**
 * @brief Extract next token ot of the line.
 * @details get_next_token() recognizes and returns one token at a time in a 
 * "input" of a line, moves the "cursor" by token length. Repeated calls for
 * the same line return next token in a line input, upon reading EOF END_TOKEN
 * type returned.
 * @param line A pointer to a line struct to be tokenized.
 * @return Returns a token, ERROR_TOKEN type in case of an error.
*/
t_token	get_next_token(t_line *line)
{
	t_token	token;

	token.slice.location = NULL;
	token.slice.length = 0;
	if (!line->input || !line->cursor || line->cursor < line->input)
	{
		token.type = ERROR_TOKEN;
		return (token);
	}
	while (*line->cursor == ' ' || *line->cursor == '\t')
		line->cursor++;
	if (*line->cursor == '\0')
	{
		token.type = END_TOKEN;
		return (token);
	}
	token = consume_token(line);
	return (token);
}
