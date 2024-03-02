/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:29:34 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/02 15:12:59 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ft_printf.h>
#include "error_handling.h"

void	panic(char *txt)
{
	ft_printf(2, "%s\n", txt);
	exit(EXIT_FAILURE);
}

void	panic_malloc(void)
{
	ft_printf(2, "%s: %s\n", MSH_NAME, strerror(errno));
	exit(EXIT_FAILURE);
}

void	error_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

static int	process_stat(char *path)
{
	int	exit_stat;

	exit_stat = EXIT_SUCCESS;
	if (errno == ENOENT)
	{
		ft_printf(2, "%s: %s\n", path, "No such file or directory\n");
		exit_stat = 127;
	}
	else if (errno == EACCES)
	{
		ft_printf(2, "%s: %s\n", path, "Permission denied\n");
		exit_stat = 126;
	}
	else
	{
		ft_printf(2, "%s: %s\n", path, strerror(errno));
		exit_stat = 127;
	}
	return (exit_stat);
}

int	execve_error_msg(char *path, char *cmd_name)
{
	struct stat	path_stat;
	int			exit_stat;

	if (path == NULL)
	{
		ft_printf(2, "%s: %s: %s\n", MSH_NAME, cmd_name, "command not found");
		return (127);
	}
	exit_stat = EXIT_SUCCESS;
	if (errno == EFAULT)
	{
		printf("PATH: %s\n", path);
		ft_printf(2, "%s: %s\n", path, "command not found\n");
		return (127);
	}
	if (stat(path, &path_stat) == -1)
		return (process_stat(path));
	if (S_ISDIR(path_stat.st_mode))
		do_this_1(path, &exit_stat);
	else
		do_this_2(path, &exit_stat);
	return (exit_stat);
}
