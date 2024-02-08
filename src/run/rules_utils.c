/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:33:30 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/07 20:05:58 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @brief Duplicates an existing file descriptor and prints error
 * @param fd1 file descriptor
 * @param fd2 file descriptor
 * @return 0 - Successful execution
 * @return -1 - Execution failed
*/
int	ft_dup2(unsigned int fd1, unsigned int fd2 )
{
	if (dup2(fd1, fd2) == -1)
	{
		perror("dup2: ");
		return (-1);
	}
	return (0);
}

/**
 * @brief Variadic function to close variable number of file descriptors
 * @param count	Number of file descriptors
 * @param ... File descriptors (int values)
 * @return 0 - Successful execution;
 * @return 1 - 'count' is zero;
 * @return -1 - Execution failed;
*/
int	ft_close(unsigned int count, ...)
{
	va_list	ap;

	if (count == 0)
		return (1);
	va_start(ap, count);
	while (count-- > 0)
	{
		if (close(va_arg(ap, int)) == -1)
		{
			perror("close: ");
			return (-1);
		}
	}
	va_end(ap);
	return (0);
}
