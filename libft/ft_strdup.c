/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:37:41 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/16 18:09:23 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

/**
 * @brief Save a copy of a string.
 * @details The ft_strdup() function allocates sufficient memory for a copy of
 * the string s1, does the copy, and returns a pointer to it. If malloc failed,
 * NULL is returned and errno is set to ENOMEM.
 * @param s1 A string to be copied.
 * @return A pointer to a new copied string. NULL if error occured.
*/
char	*ft_strdup(const char *s1, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s1[i] && i < len)
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr)
	{
		i = 0;
		while (i < len)
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = 0;
	}
	return (ptr);
}
