/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 06:18:48 by akeryan           #+#    #+#             */
/*   Updated: 2023/12/21 21:51:33 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(int fd, const char *a, ...);
int	ft_putchar(int fd, char c);
int	ft_putstr(int fd, char *p);
int	ft_putptr(int fd, void *p1);
int	ft_putnbr(int fd, int n);
int	ft_putnbr_u(int fd, unsigned int n);
int	ft_putnbr_hx(int fd, unsigned int h, int ucase);

#endif
