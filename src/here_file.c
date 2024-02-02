/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:02:17 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/02 18:46:56 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tokens.h"
#include "minishell.h"
#include "libft.h"
#include "readline/readline.h"
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

static int	create_open_file(char **ptr)
{
	int		i;
	char	*num;
	int		fd;

	i = 0;
	fd = -1;
	while (i >= 0 && fd < 0)
	{
		num = ft_itoa(i++);
		if (!num)
			return (-1);
		*ptr = ft_strjoin(MSH_TMPFIL_PREF, num);
		ft_free((void **) &num);
		if (!*ptr)
			return (-1);
		fd = open(*ptr, O_RDONLY | O_CREAT | O_EXCL, 0000666);
		if (fd < 0)
		{
			ft_free((void **) ptr);
			if (errno != EEXIST)
				return (-1);
			errno = 0;
		}
	}
	return (fd);
}

static int	fill_file(int fd, char *delim, size_t len)
{
	char	*line;
	size_t	line_len;

	line = readline(MSH_PS2);
	while (line)
	{
		line_len = ft_strlen(line);
		if (line_len == len && ft_strncmp(line, delim, len) == 0)
			break ;
		if (write(fd, line, line_len) < 0 || write(fd, "\n", 1) < 0)
		{
			ft_free((void **) &line);
			return (-1);
		}
		ft_free((void **) &line);
		line = readline(MSH_PS2);
	}
	ft_free((void **) &line);
	return (0);
}

char	*here_file(t_token token)
{
	int		fd;
	char	*filename;
	char	*delim;

	fd = create_open_file(&filename);
	if (fd < 0)
		return (NULL);
	delim = ft_substr(token.slice.location, 0, token.slice.length);
	if (!delim || fill_file(fd, delim, token.slice.length) < 0)
	{
		close(fd);
		unlink(filename);
		ft_free((void **) &filename);
		return (NULL);
	}
	if (close(fd) != 0)
	{
		unlink(filename);
		ft_free((void **) &filename);
	}
	return (filename);
}
