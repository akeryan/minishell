/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:46:12 by dabdygal          #+#    #+#             */
/*   Updated: 2024/03/01 15:19:31 by dabdygal         ###   ########.fr       */
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

	if (!value)
		return (0);
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
	if (str == NULL && *path == '.')
		return (-1);
	if (chdir(path) < 0 || resetenv("OLDPWD", str, envp) < 0)
	{
		ft_free((void **)&str);
		return (-1);
	}
	ft_free((void **)&str);
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

static int	parse_path(char **path, char ***envp)
{
	if (*path == NULL)
	{
		*path = ft_getenv("HOME", *envp);
		if (*path == NULL)
		{
			if (write(STDERR_FILENO, "minishell: cd: HOME not set\n", 28) < 0)
				return (-1);
			return (0);
		}
	}
	else if (**path == '-')
	{
		*path = ft_getenv("OLDPWD", *envp);
		if (*path == NULL)
		{
			if (write(STDERR_FILENO, "minishell: cd: OLDPWD not set\n", 30) < 0)
				return (-1);
			return (0);
		}
		*path = ft_strdup(*path);
		if (!path)
			return (-1);
	}
	return (0);
}

int	cd(const char *argv[], char ***envp)
{
	char	*path;

	path = (char *) argv[1];
	if (parse_path(&path, envp) < 0)
	{
		perror("minishell: cd");
		errno = 0;
		return (EXIT_FAILURE);
	}
	if (!path)
		return (EXIT_FAILURE);
	if (*path != '\0' && change_dir(path, envp) < 0)
	{
		write(STDERR_FILENO, "minishell: cd: ", 15);
		perror(path);
		errno = 0;
		return (EXIT_FAILURE);
	}
	if (*argv[1] == '-')
	{
		printf("%s\n", path);
		free(path);
	}
	return (EXIT_SUCCESS);
}
