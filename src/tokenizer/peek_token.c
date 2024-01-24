/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:21:48 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/24 13:52:03 by dabdygal         ###   ########.fr       */
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

}

static t_token_type	typify_token(const char *cursor)
{
	if (!cursor)
		return (EOF_TOKEN);
	else if (*cursor == '\0')
		return (NEWLINE);
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

static t_token	process_token(int move)
{
	static char	*line;
	static char	*cursor;
	t_token		token;

	if (!line || !cursor)
	{
		line = readline(MSH_PROMPT);
		cursor = line;
	}
	while (cursor && (*cursor == ' ' || *cursor == '\t'))
		cursor++;
	token.type = typify_token(cursor);
	token.slice.location = cursor;
	token.slice.length = token_len(cursor, token.type);
}
