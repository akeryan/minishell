/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:54:20 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/16 14:58:38 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static int	export_print(const char **envp)
{
	int	i;
	int	j;

	i = 0;
	while (envp[i])
	{
		if (printf("declare -x ") < 0)
			return (-1);
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
		{
			if (printf("%c", envp[i][j]) < 0)
				return (-1);
			j++;
		}
		if (envp[i][j] == '=' && printf("=\"%s\"", envp[i] + j + 1) < 0)
			return (-1);
		if (printf("\n") < 0)
			return (-1);
		i++;
	}
	return (0);
}

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

int	export(char *argv[], char ***envp)
{
	int	status;

	status = EXIT_SUCCESS;
	if (argv[1] == NULL && export_print(*envp) < 0)
		status = EXIT_FAILURE;
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
	return (status);
}
