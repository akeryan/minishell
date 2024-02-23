/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:54:20 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/23 21:06:58 by akeryan          ###   ########.fr       */
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
	if (str[i] && str[i] == '=')
		return (0);
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
		errno = 0;
		return (-1);
	}
	if (ft_putstr_fd(str, STDERR_FILENO) < 0)
	{
		errno = 0;
		return (-1);
	}
	if (ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO))
	{
		errno = 0;
		return (-1);
	}
	return (0);
}

static int	run_through_args(char **argv, char ***envp)
{
	int	status;

	status = 0;
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
			status = EXIT_FAILURE;
		argv++;
	}
	return (status);
}

int	ft_export(char *argv[], char ***envp)
{
	int	status;

	if (argv[1] == NULL && export_print(*envp) < 0)
	{
		perror("minishell: export");
		errno = 0;
		return (EXIT_FAILURE);
	}
	argv++;
	status = run_through_args(argv, envp);
	return (status);
}
