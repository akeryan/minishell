/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:42:11 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/23 15:48:49 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "libft.h"

static int	inval_arg_warn(char *str)
{
	if (ft_putstr_fd("minishell: exit: ", STDERR_FILENO) < 0)
	{
		perror("minishell: exit");
		errno = 0;
		return (-1);
	}
	if (ft_putstr_fd(str, STDERR_FILENO) < 0)
	{
		perror("minishell: exit");
		errno = 0;
		return (-1);
	}
	if (ft_putstr_fd(": numeric argument required\n", STDERR_FILENO))
	{
		errno = 0;
		return (-1);
	}
	return (0);
}

//If 1 is returned DO NOT EXIT
int	ft_exit(char *argv[])
{
	unsigned char	status;

	status = 0;
	if (ft_putstr_fd("exit\n", STDERR_FILENO) < 0)
		return (1);
	if (argv[1] && ft_str_is_int(argv[1]) == 0)
	{
		if (inval_arg_warn(argv[1]) < 0)
			return (255);
		return (255);
	}
	if (argv[1])
		status = ft_atoi(argv[1]);
	if (argv[1] && argv[2])
	{
		ft_printf(2, "minishell: exit: too many arguments\n");
		return (1);
	}
	return (status);
}
