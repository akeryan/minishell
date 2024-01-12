/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:37:41 by dabdygal          #+#    #+#             */
/*   Updated: 2023/07/10 15:21:56 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr)
	{
		i = 0;
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = 0;
	}
	return (ptr);
}
