/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 02:22:22 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/28 02:35:21 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "data.h"
#include "libft.h"

int	restore_stdout(t_data *data)
{
	if (!data)
	{
		ft_printf(2, "argument is NULL in restore_stdout\n");
		return (-1);
	}
	if (data->great_fd >= 0)
	{
		if (dup2(data->great_fd, STDOUT_FILENO) == -1)
		{
			perror("dup2 in restore_stdout");
			return (-1);
		}
		close(data->great_fd);
	}
	return (0);
}

int	restore_stdin(t_data *data)
{
	if (!data)
	{
		ft_printf(2, "argument is NULL in restore_stdin\n");
		return (-1);
	}
	if (data->less_fd >= 0)
	{
		if (dup2(data->less_fd, STDIN_FILENO) == -1)
		{
			perror("dup2 in restore_stdin");
			return (-1);
		}
		close(data->less_fd);
	}
	return (0);
}
