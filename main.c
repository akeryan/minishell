/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:21:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/15 11:34:37 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdio.h>
#include "readline/readline.h"
#include "readline/history.h"
#include <stdlib.h>

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline(MSH_PROMPT);
		if (input == NULL)
		{
			printf(EXIT_MSG);
			return (EXIT_SUCCESS);
		}
		add_history(input);
		printf("The command entered: %s\n", input);
		ft_free(input);
	}
	return (EXIT_SUCCESS);
}
