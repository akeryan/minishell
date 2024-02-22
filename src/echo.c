/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:10:03 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/22 15:38:00 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	echo(const char *argv[])
{
	int	n;
	int	i;

	n = 1;
	i = 1;
	if (argv[i] && ft_strncmp(argv[i], "-n", 3) == 0)
	{
		n = 0;
		i++;
	}
	while (argv[i])
	{
		if (printf("%s", argv[i]) < 0)
			return (EXIT_FAILURE);
		if (argv[i + 1])
		{
			if (printf(" ") < 0)
				return (EXIT_FAILURE);
		}
		i++;
	}
	if (n)
		printf ("\n");
	return (EXIT_SUCCESS);
}
