/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:53:33 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/21 10:55:07 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <stdlib.h>

static int	is_valid_entry(char *str)
{
	int	i;

	if (*str == '\0' || ft_isdigit(*str))
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	inval_arg_warn(char *str)
{
	if (ft_putstr_fd("minishell: unset: `", STDERR_FILENO) < 0)
	{
		perror("minishell: unset");
		errno = 0;
		return (-1);
	}
	if (ft_putstr_fd(str, STDERR_FILENO) < 0)
	{
		perror("minishell: unset");
		errno = 0;
		return (-1);
	}
	if (ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO))
	{
		perror("minishell: unset");
		errno = 0;
		return (-1);
	}
	return (0);
}

static void	env_unset(char *name, char **envp)
{
	int		i;
	size_t	len;

	len = ft_strlen(name);
	while (*envp)
	{
		if (ft_strncmp(name, *envp, len) == 0)
		{
			if ((*envp)[len] == '\0' || (*envp)[len] == '=')
				break ;
		}
		envp++;
	}
	if (*envp)
	{
		i = 0;
		while (envp[i + 1])
			i++;
		free(*envp);
		*envp = NULL;
		*envp = envp[i];
		envp[i] = NULL;
	}
}

int	unset(char *argv[], char **envp)
{
	int	status;

	status = EXIT_SUCCESS;
	argv++;
	while (*argv)
	{
		if (is_valid_entry(*argv))
			env_unset(*argv, envp);
		else
		{
			status = EXIT_FAILURE;
			if (inval_arg_warn(*argv) == 0)
				return (EXIT_FAILURE);
		}
		argv++;
	}
	return (status);
}
