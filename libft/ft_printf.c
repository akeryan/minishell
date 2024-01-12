/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:56:03 by dabdygal          #+#    #+#             */
/*   Updated: 2023/07/18 18:06:38 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <inttypes.h>
#include <unistd.h>

static int	print_u(const uintmax_t u)
{
	uintmax_t		i;
	unsigned int	a;
	char			c;
	int				done;

	a = u;
	done = 0;
	i = 10;
	while (a / i)
		i *= 10;
	i /= 10;
	while (i > 0)
	{
		c = (char)((a / i) % 10 + 48);
		write(1, &c, sizeof(char));
		done++;
		i /= 10;
	}
	return (done);
}

static int	print_ptr(uintptr_t p)
{
	int				done;
	unsigned int	i;

	done = 2;
	ft_putstr_fd("0x", 1);
	i = 1;
	while (i < (sizeof(uintptr_t) * 2) && p >> (4 * i))
		i++;
	while (i--)
	{
		if (((p >> (4 * i)) & 15) < 10)
			ft_putchar_fd(((p >> (4 * i)) & 15) + '0', 1);
		else
			ft_putchar_fd(((p >> (4 * i)) & 15) - 10 + 'a', 1);
		done++;
	}
	return (done);
}

static int	print_hex(unsigned int h, const char c)
{
	int				done;
	unsigned int	i;

	i = 1;
	done = 0;
	while (i < (sizeof(unsigned int) * 2) && h >> (4 * i))
		i++;
	while (i--)
	{
		if (((h >> (4 * i)) & 15) < 10)
			ft_putchar_fd(((h >> (4 * i)) & 15) + '0', 1);
		else if (c != 'X')
			ft_putchar_fd(((h >> (4 * i)) & 15) - 10 + 'a', 1);
		else
			ft_putchar_fd(((h >> (4 * i)) & 15) - 10 + 'A', 1);
		done++;
	}
	return (done);
}

static int	conv_and_print(va_list ap, const char *c)
{
	int			done;

	done = 0;
	if (*c == '%')
		done = ft_putchar_fd('%', 1);
	else if (*c == 'c')
		done = ft_putchar_fd(va_arg(ap, int), 1);
	else if (*c == 's')
		done = ft_putstr_fd(va_arg(ap, const char *const), 1);
	else if (*c == 'x' || *c == 'X')
		done = print_hex(va_arg(ap, uintmax_t), *c);
	else if (*c == 'p')
		done = print_ptr(va_arg(ap, uintptr_t));
	else if (*c == 'd' || *c == 'i')
		done = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*c == 'u')
		done = print_u(va_arg(ap, uintmax_t));
	return (done);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		done;

	if (!format)
		return (-1);
	done = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			done += conv_and_print(ap, format);
		}
		else
			done += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(ap);
	return (done);
}
