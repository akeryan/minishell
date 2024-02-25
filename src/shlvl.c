/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:52:04 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/25 16:14:02 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	handle_shlvl(char ***envp)
{
	char	*shlvl;
	int		x;

	shlvl = ft_getenv("SHLVL", *envp);
	if (!shlvl || *shlvl == '\0' || ft_str_is_int(shlvl) == 0)
	{
		if (ft_setenv("SHLVL", "1", 1, envp) < 0)
		{
			perror("minishell: ft_setenv");
			return (-1);
		}
		return (0);
	}
	if (ft_atoi(shlvl) < 0)
		x = 0;
	else
		x = ft_atoi(shlvl) + 1;
	shlvl = ft_itoa(x);
	if (!shlvl || ft_setenv("SHLVL", shlvl, 1, envp) < 0)
	{
		perror("minishell: setenv");
		return (-1);
	}
	free(shlvl);
	return (0);
}
