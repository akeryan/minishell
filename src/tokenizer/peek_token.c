/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:21:48 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/24 12:29:49 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tokens.h"
#include "minishell.h"
#include "readline/readline.h"
#include "readline/history.h"

t_token	process_token(int move)
{
	static char	*line;
	static char	*cursor;
	t_token		token;

	if (!line || !cursor)
	{
		line = readline(MSH_PROMPT);
		cursor = line;
	}
	while (*cursor == ' ' || *cursor == '\t')
		cursor++;
	token.type = typify(cursor);
	token.slice.location = cursor;
	token.slice.length = token_len(cursor, token.type);
}
