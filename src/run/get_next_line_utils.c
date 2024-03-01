/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:41:53 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/01 16:11:43 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"

//size_t	ft_strlen(const char *str)
//{
	//size_t	len;
	//if (str == NULL)
		//return(0);
		//// ft_printf(2, "str argument is NULL\n");	
	//if (!str)
		//return (0);
		//// ft_printf(2, "str argument is NULL\n");
	//printf("str: %s\n", str);
	//len = 0;
	//while (str && str[len])
		//len++;
	//return (len);
//}

char	*ft_attach(char *tail, char *buf, size_t size)
{
	char	*str;
	char	*tail_ptr;
	char	*buf_ptr;
	int		i;

	if (tail == NULL)
		return (NULL);
	if (buf == NULL || size == 0)
		return (tail);
	str = (char *)malloc(ft_strlen(tail) + size + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	tail_ptr = tail;
	buf_ptr = buf;
	while (*tail_ptr)
		str[++i] = *tail_ptr++;
	while (size--)
		str[++i] = *buf_ptr++;
	str[++i] = '\0';
	free(tail);
	tail = NULL;
	return (str);
}

int	ft_has_nl(char *tail)
{
	int	i;

	if (tail == NULL)
		return (-1);
	i = 0;
	while (tail[i])
	{
		if (tail[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char const *str, unsigned int start, size_t length)
{
	char	*ptr;
	size_t	i;

	if (start >= ft_strlen(str))
		length = 0;
	else if (length > ft_strlen(&str[start]))
		length = ft_strlen(&str[start]);
	ptr = (char *)malloc(sizeof (*ptr) * length + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		ptr[i] = str[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_read(int fd, char **tail, char **buf)
{
	int		nl;
	ssize_t	bsize;

	nl = ft_has_nl(*tail);
	bsize = 1;
	while (nl == -1 && bsize > 0)
	{
		bsize = read(fd, *buf, BUFFER_SIZE);
		if (bsize > 0)
		{		
			*tail = ft_attach(*tail, *buf, bsize);
			nl = ft_has_nl(*tail);
		}
	}	
	return (nl);
}
