/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:14:13 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/02 15:14:22 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ft_printf.h>
#include "error_handling.h"

void	do_this_1(char *path, int *exit_stat)
{
	ft_printf(2, "%s: %s: %s\n", MSH_NAME, path, "is a directory");
	*exit_stat = 126;
}

void	do_this_2(char *path, int *exit_stat)
{
	ft_printf(2, "%s: %s: %s\n", MSH_NAME, path, "Permission denied\n");
	*exit_stat = 126;
}
