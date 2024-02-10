/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 06:13:42 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/21 21:47:57 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(int fd, unsigned int nb)
{
	const char	*base = "0123456789";

	if (nb < 10)
		return (ft_putchar(fd, base[nb]));
	return (ft_putnbr_u(fd, nb / 10) + ft_putnbr_u(fd, nb % 10));
}
