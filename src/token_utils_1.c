/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:26:35 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/07 14:51:54 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokens.h"
#include "libft.h"

t_token_type	typify_token(const char *cursor)
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

size_t	word_len(const char *str)
{
	char			delim;
	t_token_type	type;
	size_t			i;

	i = 0;
	delim = ' ';
	type = typify_token(str);
	while (str[i] && ((str[i] != ' ' && type == WORD) || delim != ' '))
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			if (delim == ' ')
				delim = str[i];
			else if (str[i] == delim)
				delim = ' ';
		}
		i++;
		type = typify_token(str + i);
	}
	if (str[i] && delim != ' ')
		i++;
	return (i);
}
