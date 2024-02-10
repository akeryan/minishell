/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 04:42:28 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/21 21:54:10 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switch(int fd, va_list ap, char ch)
{
	int	len;

	len = 0;
	if (ch == 'c')
		len = ft_putchar(fd, va_arg(ap, int));
	else if (ch == 's')
		len = ft_putstr(fd, va_arg(ap, char *));
	else if (ch == 'p')
		len = ft_putptr(fd, va_arg(ap, void *));
	else if (ch == 'd' || ch == 'i')
		len = ft_putnbr(fd, va_arg(ap, int));
	else if (ch == 'u')
		len = ft_putnbr_u(fd, va_arg(ap, unsigned int));
	else if (ch == 'x')
		len = ft_putnbr_hx(fd, va_arg(ap, unsigned int), 0);
	else if (ch == 'X')
		len = ft_putnbr_hx(fd, va_arg(ap, unsigned int), 1);
	else if (ch == '%')
		len = ft_putchar(fd, '%');
	return (len);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			len += ft_switch(fd, ap, *(str + 1));
			str += 2;
		}
		else
		{
			ft_putchar(fd, *str);
			len++;
			str++;
		}
	}
	va_end(ap);
	return (len);
}
