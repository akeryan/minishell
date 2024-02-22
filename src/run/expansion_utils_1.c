/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:06:26 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/22 23:04:39 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <stdbool.h>
#include "libft.h"
#include "expansion.h"
#include "data.h"

int	does_dir_exist(const char *path)
{
	struct stat	status;

	if (stat(path, &status) != 0)
		return (0);
	return (S_ISDIR(status.st_mode));
}

void	remove_quotation_marks(char **word)
{
	char	*str;
	bool	sngl_qm;
	bool	dble_qm;
	
	sngl_qm = false;
	dble_qm = false;
	str = *word;
	while (*str != '\0')
	{
		if (*str == '\'' && !dble_qm)
		{
			ft_strlcpy(str, str + 1, ft_strlen(str));
			sngl_qm = !sngl_qm;
			continue ;
		}	
		if (*str == '"' && !sngl_qm)
		{
			ft_strlcpy(str, str + 1, ft_strlen(str));
			dble_qm = !dble_qm;
			continue ;
		}
		str++;
	}
}

void	apply_expansions(char **word, t_data *d)
{
	if (!*word)
		return ;
	tilde_expansion(word, &d->env);
	dollar_expansion(word, d);
	remove_quotation_marks(word);
}
