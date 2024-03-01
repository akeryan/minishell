/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:11:56 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/01 12:31:59 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"
#include "error_handling.h"
#include "main_utils.h"

static char	*cmd_in_path(char *path, char *cmd);

/**
 * @brief Finds the location of the utility on the system
 * @param cmd Name of the utility
 * @return Path to the location of the utility
*/
char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*pth;
	int		i;

	if (cmd == NULL)
		return (NULL);
	path = ft_getenv("PATH", envp);
	if (path == NULL)
	{
		ft_printf(2, "minishell: %s: No such file or directory\n", cmd);
		exit(127);
	}
	paths = ft_split(path, ':');
	if (paths == NULL)
		panic_malloc();
	i = 0;
	while (paths[++i])
	{
		pth = cmd_in_path(paths[i], cmd);
		if (pth)
			return (clean_dblptr(paths), pth);
	}
	return (clean_dblptr(paths), NULL);
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
		panic_malloc();
	ft_free((void **)&pth[0]);
	if (access(pth[1], F_OK) == 0)
		return (pth[1]);
	ft_free((void **)&pth[1]);
	return (NULL);
}
