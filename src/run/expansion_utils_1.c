/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:06:26 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/20 20:04:48 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
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

	str = *word;
	while (*str != '\0')
	{
		if (*str == '"' || *str == '\'')
		{
			ft_strlcpy(str, str + 1, ft_strlen(str));
			continue ;
		}
		str++;
	}
}

void	apply_expansions(char **word, t_data *d)
{
	tilde_expansion(word, d->env);
	dollar_expansion(word, d);
	remove_quotation_marks(word);
}
