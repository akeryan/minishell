/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 23:43:48 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/21 21:54:34 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int fd, int nb)
{
	const char	*base = "0123456789";

	if (nb == -2147483648)
		return (ft_putstr(fd, "-2147483648"));
	if (nb < 0)
		return (ft_putchar(fd, '-') + ft_putnbr(fd, -nb));
	if (nb < 10)
		return (ft_putchar(fd, base[nb]));
	return (ft_putnbr(fd, nb / 10) + ft_putnbr(fd, nb % 10));
}
