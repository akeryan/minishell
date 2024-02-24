/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:48:35 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/24 23:07:09 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE	256

size_t	ft_strlen(const char *str);
int		ft_has_nl(char *tail);
char	*ft_substr(char const *str, unsigned int start, size_t length);
char	*get_next_line(int fd);
char	*ft_attach(char *tail, char *buf, size_t size);
int		ft_read(int fd, char **tail, char **buf);

#endif
