/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 06:12:27 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/21 21:47:27 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hx(int fd, unsigned int a, int ucase)
{
	const char	*base = "0123456789abcdef";
	const char	*ubase = "0123456789ABCDEF";

	if (ucase == 1)
		base = ubase;
	if (a < 16)
		return (ft_putchar(fd, base[a]));
	return (ft_putnbr_hx(fd, a / 16, ucase) + ft_putnbr_hx(fd, a % 16, ucase));
}
