/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:27:25 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/21 14:37:59 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int	pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
	{
		perror(NULL);
		errno = 0;
		return (EXIT_FAILURE);
	}
	if (printf("%s\n", path) < 0)
	{
		free(path);
		return (EXIT_FAILURE);
	}
	free(path);
	return (EXIT_SUCCESS);
}
