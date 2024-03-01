/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:51:42 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/01 19:12:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_init(int fd, char **tail, char **buf)
{
	if (fd < 0 || fd >= 256 || BUFFER_SIZE <= 0)
		return (-1);
	if (*tail == NULL)
	{
		*tail = (char *)malloc(1);
		if (*tail == NULL)
			return (0);
		*tail[0] = '\0';
	}
	*buf = (char *)malloc(BUFFER_SIZE);
	if (*buf == NULL)
		return (0);
	return (1);
}

static void	ft_free2(char **buf, char **tail)
{
	if ((*tail)[0] == '\0' || *tail == NULL)
	{
		free(*tail);
		*tail = NULL;
	}
	free(*buf);
	*buf = NULL;
}

static int	ft_check_nl(int nl, char **buf, char **tail)
{
	if (nl == -1 && (*tail)[0])
		return (ft_strlen(*tail));
	if (nl == -1 && (*tail)[0] == '\0')
	{
		ft_free2(buf, tail);
		return (-1);
	}
	return (nl);
}

char	*get_next_line(int fd)
{	
	static char	*tail[1024];
	char		*buf;	
	char		*next_line;
	int			nl;
	char		*temp;

	nl = ft_init(fd, &tail[fd], &buf);
	if (nl == -1)
		return (NULL);
	if (nl == 0)
	{	
		ft_free2(&buf, &tail[fd]);
		return (NULL);
	}			
	nl = ft_read(fd, &tail[fd], &buf);
	nl = ft_check_nl(nl, &buf, &tail[fd]);
	if (nl == -1)
		return (NULL);
	next_line = ft_substr_my(tail[fd], 0, nl + 1);
	temp = ft_substr(tail[fd], nl + 1, ft_strlen(&tail[fd][nl + 1]));
	free(tail[fd]);
	tail[fd] = temp;
	ft_free2(&buf, &tail[fd]);
	return (next_line);
}
