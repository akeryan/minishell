/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:06:26 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/20 14:25:15 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include "expansion.h"
#include "data.h"

int	does_dir_exist(const char *path)
{
	struct stat	status;

	if (stat(path, &status) != 0)
		return (0);
	return (S_ISDIR(status.st_mode));
}

void	apply_expansions(char **word, t_data *d)
{
	printf("BEFORE EXPANSIONS: %s\n", *word);
	tilde_expansion(word, d->env);
	printf("AFTER TILDE EXPANSION: %s\n", *word);
	dollar_expansion(word, d);
	printf("AFTER DOLLAR EXPANSION: %s\n", *word);
}
