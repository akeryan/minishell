/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:46:12 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/13 17:35:25 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	change_dir(char *path, char **envp)
{
	char	*oldpwd;

	if (ft_getenv("OLDPWD", envp))
	{
		oldpwd = getcwd(NULL, 0);
		if (oldpwd == NULL)
			return (-1);
	}
}

int	cd(const char *argv[], char **envp)
{
	char	*path;

	if (argv[1] && argv[2])
	{
		write(STDERR_FILENO, "minishell: cd: too many arguments\n", 34);
		return (EXIT_FAILURE);
	}
	path = argv[1];
	if (path == NULL)
	{
		path = ft_getenv("HOME", envp);
		if (path == NULL)
		{
			write(STDERR_FILENO, "minishell: cd: HOME not set\n", 28);
			return (EXIT_FAILURE);
		}
	}
	if (change_dir(path, envp) < 0)
	{
		write(STDERR_FILENO, "minishell: cd: ", 15);
		perror(path);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
