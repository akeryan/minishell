/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:11:56 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/10 16:24:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"
#include "free.h"
#include "error_handling.h"

static char	*cmd_in_path(char *path, char *cmd);

/**
 * @brief Finds the location of the utility on the system
 * @param cmd Name of the utility
 * @return Path to the location of the utility
*/
char	*get_cmd_path(char *cmd)
{
	char	**paths;
	char	*pth;
	int		i;

	if (cmd == NULL)
	{
		ft_printf(2, "Error: command is empty\n");
		return (NULL);
	}
	paths = ft_split(getenv("PATH"), ':');
	//error_check(paths, "Memory allocation failed in ft_split()", PTR);
	i = 0;
	while (paths[++i])
	{
		pth = cmd_in_path(paths[i], cmd);
		if (pth)
		{
			free_split(paths);
			return (pth);
		}
	}
	//ft_printf(2, "Error: command not found: %s\n", cmd);
	free_split(paths);
	return (NULL);	
}

/**
 * @brief Checks whether command exists in the provided location on the system
 * @param path Path to the location on the system
 * @param cmd Name of the utility
 * @return Full path to the utility
*/
static char	*cmd_in_path(char *path, char *cmd)
{
	char	*pth[2];

	pth[0] = ft_strjoin(path, "/");
	pth[1] = ft_strjoin(pth[0], cmd);
	if (!pth[0] || !pth[1])
	{
		perror("malloc: ");
		return (NULL);
	}
	free(pth[0]);
	if (access(pth[1], F_OK) == 0)
		return (pth[1]);
	free(pth[1]);
	return (NULL);
}
