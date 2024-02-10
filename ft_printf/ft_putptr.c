/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 05:51:03 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/21 21:55:04 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexi(int fd, unsigned long long a)
{
	const char	*base = "0123456789abcdef";

	if (a < 16)
		return (ft_putchar(fd, base[a]));
	return (ft_putnbr_hexi(fd, a / 16) + ft_putnbr_hexi(fd, a % 16));
}

int	ft_putptr(int fd, void *p)
{
	int	len;

	len = 0;
	len += ft_putstr(fd, "0x");
	len += ft_putnbr_hexi(fd, (unsigned long long)p);
	return (len);
}
