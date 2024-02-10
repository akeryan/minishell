/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 10:23:51 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/21 21:52:06 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(int fd, char *str)
{
	if (str == NULL)
		return (ft_putstr(fd, "(null)"));
	if (*str == '\0')
		return (0);
	return (ft_putchar(fd, *str) + ft_putstr(fd, str + 1));
}
