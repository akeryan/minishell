/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:44:06 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/16 17:45:23 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	is_done(int i, int *done)
{
	while (*done >= 0)
	{
		if (i == *done)
			return (1);
		done++;
	}
	return (0);
}

static int	format_print(const char *str)
{
	int	i;

	i = 0;
	if (ft_putstr_fd("declare -x ", STDOUT_FILENO) < 0)
		return (-1);
	while (str[i] && str[i] != '=')
	{
		if (ft_putchar_fd(str[i], STDOUT_FILENO) < 0)
			return (-1);
		i++;
	}
	if (str[i] == '=')
	{
		if (ft_putstr_fd("=\"", 1) < 0 || ft_putstr_fd(str + i + 1, 1) < 0)
			return (-1);
		if (ft_putchar_fd('"', STDOUT_FILENO) < 0)
			return (-1);
	}
	if (ft_putchar_fd('\n', STDOUT_FILENO) < 0)
		return (-1);
	return (0);
}

static int	sel_print(char **envp, int *done)
{
	int	i;
	int	min;

	min = 0;
	while (envp[min] && is_done(min, done))
		min++;
	if (envp[min] == NULL)
		return (0);
	i = 0;
	while (envp[i])
	{
		if (is_done(i, done) == 0 && ft_strcmp(envp[min], envp[i]) > 0)
			min = i;
		i++;
	}
	if (format_print(envp[min]) < 0)
		return (-1);
	i = 0;
	while (done[i] >= 0)
		i++;
	done[i] = min;
	if (sel_print(envp, done) < 0)
		return (-1);
	return (0);
}

int	export_print(char **envp)
{
	int	i;
	int	*done;

	if (*envp == NULL)
		return (0);
	i = 0;
	while (envp[i])
		i++;
	done = (int *) malloc(sizeof(int) * (i + 1));
	if (!done)
		return (-1);
	while (i >= 0)
	{
		done[i] = -1;
		i--;
	}
	if (sel_print(envp, done) < 0)
	{
		free(done);
		return (-1);
	}
	free(done);
	return (0);
}
