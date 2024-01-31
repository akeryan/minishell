/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:21:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/31 16:12:28 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include "grammar.h"

int	g_signal;

static char	*token_type(t_token_type type)
{
	if (type == EOF_TOKEN)
		return ("EOF");
	else if (type == NEWLINE_TOKEN)
		return ("NEWLINE");
	else if (type == PIPE)
		return ("PIPE");
	else if (type == DLESS)
		return ("DLESS");
	else if (type == DGREAT)
		return ("DGREAT");
	else if (type == LESS)
		return ("LESS");
	else if (type == GREAT)
		return ("GREAT");
	else if (type == WORD)
		return ("WORD");
	return ("ERROR!!!");
}

int	main(void)
{
	t_token		token;
	t_grammar	grammar;

	grammar = setup_grammar();
	while (1)
	{
		token = consume_token();
		printf("%s(%zu) ", token_type(token.type), token.slice.length);
		if (token.type == NEWLINE_TOKEN)
			printf("\n");
		if (token.type == EOF_TOKEN)
		{
			printf(EXIT_MSG);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
