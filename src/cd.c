/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:46:12 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/16 10:51:22 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"

static int	resetenv(const char *name, const char *value, char ***envp)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(name);
	while (envp[0][i])
	{
		if (ft_strncmp(name, envp[0][i], len) == 0)
		{
			if (envp[0][i][len] == '\0' || envp[0][i][len] == '=')
			{
				if (ft_setenv(name, value, 1, envp) < 0)
					return (-1);
				return (0);
			}
		}
		i++;
	}
	return (0);
}

static int	change_dir(char *path, char ***envp)
{
	char	*str;

	str = getcwd(NULL, 0);
	if (str == NULL)
		return (-1);
	if (chdir(path) < 0 || resetenv("OLDPWD", str, envp) < 0)
	{
		free(str);
		return (-1);
	}
	free (str);
	str = getcwd(NULL, 0);
	if (str == NULL)
		return (-1);
	if (resetenv("PWD", str, envp) < 0)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

int	cd(const char *argv[], char ***envp)
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
		path = ft_getenv("HOME", *envp);
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
		errno = 0;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
