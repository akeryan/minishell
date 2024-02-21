/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:27:25 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/21 15:23:35 by akeryan          ###   ########.fr       */
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
