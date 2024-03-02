/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:48:35 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/02 14:09:22 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE	256

int		ft_has_nl(char *tail);
char	*ft_substr_my(char const *str, unsigned int start, size_t length);
char	*ft_get_next_line(int fd);
char	*ft_attach(char *tail, char *buf, size_t size);
int		ft_read(int fd, char **tail, char **buf);

#endif
