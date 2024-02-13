/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_strv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:28:26 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/13 16:58:14 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	strv_size(const char **strv)
{
	size_t	i;

	if (!strv)
		return (0);
	i = 0;
	while (strv[i])
		i++;
	return (i);
}

static void	free_strv(char **strv)
{
	while (*strv)
	{
		free(*strv);
		*strv = NULL;
		strv++;
	}
}

char	**ft_copy_strv(const char **strv)
{
	int		size;
	char	**envp;

	if (strv == NULL)
		return (NULL);
	size = strv_size(strv);
	envp = (char **) malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	envp[size + 1] = NULL;
	while (size >= 0)
	{
		envp[size] = ft_strdup(strv[size]);
		if (envp[size] == NULL)
		{
			free_strv(envp + size + 1);
			return (NULL);
		}
		size--;
	}
	return (envp);
}
