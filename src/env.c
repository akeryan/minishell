/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:24:40 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/21 16:07:26 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"

static int	inval_arg_warn(char *str)
{
	if (ft_putstr_fd("env: ", STDERR_FILENO) < 0)
	{
		perror("minishell: env");
		errno = 0;
		return (-1);
	}
	if (ft_putstr_fd(str, STDERR_FILENO) < 0)
	{
		perror("minishell: env");
		errno = 0;
		return (-1);
	}
	if (ft_putstr_fd(": arguments are not allowed\n", STDERR_FILENO))
	{
		perror("minishell: env");
		errno = 0;
		return (-1);
	}
	return (0);
}

static int	env_print(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '\0')
		return (0);
	if (ft_putstr_fd(str, 1) < 0 || ft_putstr_fd("\n", 1) < 0)
	{
		perror("minishell: env");
		errno = 0;
		return (-1);
	}
	return (0);
}

int	env(char *argv[], char **envp)
{
	if (argv[1])
	{
		if (inval_arg_warn(argv[1]) < 0)
			return (EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	while (*envp)
	{
		if (env_print(*envp) < 0)
			return (EXIT_FAILURE);
		envp++;
	}
	return (EXIT_SUCCESS);
}
