/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:31:55 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/27 14:59:54 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_array_of_strings(char **arr)
{
	if (!arr)
		return ;
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
}
