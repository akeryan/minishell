/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:54:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/29 17:28:50 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

void redir_read(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		//ft_printf(2, "Error: open failed: %s: %s\n", strerror(errno), file);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		//ft_printf(2, "Error: dup2 in dup_infile: %s\n", strerror(errno));
	close(fd);
}

void redir_write(char *file_name)
{
	int fd;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		//ft_printf(2, "Error: open failed: %s: %s\n", strerror(errno), file);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		//ft_printf(2, "Error: dup2 in dup_outfile: %s\n", strerror(errno));
	close(fd);
}

void redir_append(char *file_name)
{
	int fd;

	fd = open(file_name, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
	{
		//ft_printf(2, "Error: open failed: %s: %s\n", strerror(errno), file);
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		//ft_printf(2, "Error: dup2 in dup_outfile: %s\n", strerror(errno));
	close(fd);
}