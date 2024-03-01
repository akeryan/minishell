/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:56:24 by dabdygal          #+#    #+#             */
/*   Updated: 2024/03/01 16:32:33 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s || s == NULL)
	{
		printf("str argument is NULL\n");
		return (0);
	}
	i = 0;
	while (s && *(s + i))
	{
		i++;
	}
	return (i);
}
