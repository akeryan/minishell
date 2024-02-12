/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:46:12 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/12 18:56:51 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	change_dir(char *str)
{
	char	*oldpwd;

	if (getenv("OLDPWD"))
	{
		oldpwd = getcwd(NULL, 0);
		if (oldpwd == NULL)
			return (-1);
	}
}

int	cd(const char *argv[])
{
	char	*str;

	if (argv[1] && argv[2])
	{
		write(STDERR_FILENO, "minishell: cd: too many arguments\n", 34);
		return (EXIT_FAILURE);
	}
	str = argv[1];
	if (argv[1] == NULL)
	{
		str = getenv("HOME");
		if (str == NULL)
		{
			write(STDERR_FILENO, "minishell: cd: HOME not set\n", 28);
			return (EXIT_FAILURE);
		}
	}
	if (change_dir(str) < 0)
	{
		write(STDERR_FILENO, "minishell: cd: ", 15);
		perror(str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
