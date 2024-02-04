/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:29:34 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/04 20:51:43 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <ft_printf.h>
#include "error_handling.h"

void	execve_error_msg(char *cmd_name)
{
	if (errno == EACCES | EISDIR | EPERM | ENOENT | ELOOP)
		ft_printf (2, "%s: %s: %s\n", MSH_NAME, cmd_name, strerror(errno));
	else
		ft_printf(2, "%s: %s\n", MSH_NAME, strerror(errno));
}

void	malloc_error_msg(void)
{
	perror("malloc: ");
	//if (errno != 0)
		//ft_printf(2, "%s: %s\n", MSH_NAME, strerror(errno));
	//else
		//ft_printf(2, "%s: %s\n", MSH_NAME, ALLOC_ERR);
}