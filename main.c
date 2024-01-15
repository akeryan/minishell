/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:21:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/15 19:36:05 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include "readline/history.h"
#include <stdlib.h>
#include "tokens.h"

int	main(void)
{
	t_line	line;
	t_token	token;

	while (1)
	{
		line = ft_readline(MSH_PROMPT);
		if (line.input == NULL)
		{
			if (printf(EXIT_MSG) < 0)
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		add_history(line.input);
		printf("The command entered: %s\n", line.input);
		token.type = ERROR_TOKEN;
		while (token.type != END_TOKEN)
		{
			token = get_next_token(&line);
			printf("Token: %i; length: %zu\n", token.type, token.slice.length);
		}
		ft_free(line.input);
		line.cursor = NULL;
	}
	return (EXIT_SUCCESS);
}
