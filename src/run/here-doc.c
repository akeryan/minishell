/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here-doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 23:19:24 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/25 23:44:08 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "rules.h"
#include "error_handling.h"
#include "expansion.h"
#include "data.h"
#include "get_next_line.h"
#include "libft.h"

static int	open_file_1(char *file_name, char *new_file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		unlink(file_name);
		free(new_file_name);
		error_exit("open");
	}
	return (fd);
}

static int	open_file_2(char *new_file_name, char *file_name, int fd)
{
	int	fd2;

	fd2 = open(new_file_name, O_RDWR | O_CREAT | O_EXCL, 0666);
	if (fd2 == -1)
	{
		close(fd);
		unlink(file_name);
		free(new_file_name);
		error_exit("open");
	}
	return (fd2);
}

static void	read_write(int fd, int fd2, t_data *data)
{
	char	*str;

	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		*(ft_strchr(str, '\n')) = '\0';
		dollar_expansion(&str, data);
		*(ft_strchr(str, '\0')) = '\n';
		write(fd2, str, ft_strlen(str));
		free(str);
		str = NULL;
	}
}

void	here_doc(char *file_name, t_data *data)
{
	int		fd;
	int		fd2;
	char	*new_file_name;

	if (!file_name)
		return ;
	new_file_name = ft_strjoin(file_name, "_42");
	if (new_file_name == NULL)
		panic_malloc();
	fd = open_file_1(file_name, new_file_name);
	fd2 = open_file_2(new_file_name, file_name, fd);
	read_write(fd, fd2, data);
	close(fd2);
	redir_read(new_file_name);
	free(new_file_name);
	close(fd);
	if (unlink(new_file_name) == -1)
		error_exit("unlink");
	if (unlink(file_name) == -1)
		error_exit("unlink");
}
