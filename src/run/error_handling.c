/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:29:34 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/14 20:36:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <ft_printf.h>
#include "error_handling.h"

void	path_error_msg(char *cmd_name)
{
	ft_printf (2, "%s: %s: %s\n", MSH_NAME, cmd_name, PATH_ERR);
	exit(127);
}

void	panic_malloc(void)
{
	ft_printf(2, "%s: %s\n", MSH_NAME, strerror(errno));
	exit(EXIT_FAILURE);
}

void	execve_error_msg(char *cmd_name)
{
	if (errno == EACCES | \
		errno == EISDIR | \
		errno == EPERM | \
		errno == ENOENT | \
		errno == ELOOP)
		ft_printf (2, "%s: %s: %s\n", MSH_NAME, cmd_name, strerror(errno));
	else
		ft_printf(2, "%s: %s\n", MSH_NAME, strerror(errno));
}

void	error_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
