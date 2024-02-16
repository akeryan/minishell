/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:54:20 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/16 17:33:37 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int	is_valid_entry(const char *str)
{
	int	i;

	if (*str == '\0' || ft_isdigit(*str))
		return (0);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	export_entry(const char *str, char ***envp)
{
	size_t	i;
	char	*name;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '\0')
	{
		if (ft_setenv(str, NULL, 0, envp) < 0)
			return (-1);
	}
	else
	{
		name = ft_substr(str, 0, i);
		if (!name)
			return (-1);
		if (ft_setenv(name, str + i + 1, 1, envp) < 0)
		{
			free(name);
			return (-1);
		}
		free(name);
	}
	return (0);
}

static int	inval_arg_warn(char *str)
{
	if (ft_putstr_fd("minishell: export: `", STDERR_FILENO) < 0)
	{
		perror("minishell: export");
		errno = 0;
		return (-1);
	}
	if (ft_putstr_fd(str, STDERR_FILENO) < 0)
	{
		perror("minishell: export");
		errno = 0;
		return (-1);
	}
	if (ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO))
	{
		perror("minishell: export");
		errno = 0;
		return (-1);
	}
	return (0);
}

int	ft_export(char *argv[], char ***envp)
{
	if (argv[1] == NULL && export_print(*envp) < 0)
	{
		perror("minishell: export");
		errno = 0;
		return (EXIT_FAILURE);
	}
	argv++;
	while (*argv)
	{
		if (is_valid_entry(*argv))
		{
			if (export_entry(*argv, envp) < 0)
			{
				perror("minishell: export");
				errno = 0;
				return (EXIT_FAILURE);
			}
		}
		else if (inval_arg_warn(*argv) < 0)
			return (EXIT_FAILURE);
		argv++;
	}
	return (EXIT_SUCCESS);
}
