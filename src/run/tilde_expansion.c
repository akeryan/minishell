/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:10:13 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/14 20:37:18 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*tilde_expansion(char **word)
{
	char	*slash;
	char	*usr_name;
	char	*usrs_dir;
	char	*tmp;
	char	*home_dir;

	usr_name = "akeryan";
	usrs_dir = "/Users/";
	home_dir = "/Users/akeryan";

	if (!word)
		return (NULL);
	if (*word[0] != '~')
		return (NULL);
	slash = is_there_unquoted_slash(*word);
	if (!slash)
	{
		if (*(*word + 1) == '\0')
			tmp = ft_strjoin(usrs_dir, usr_name);
		else
			tmp = ft_strjoin(usrs_dir, *word + 1);
	}
	else
	{
		if (*(*word + 1) == '/')
			tmp = ft_strjoin(home_dir, *word + 1);
		else
			tmp = ft_strjoin(usrs_dir, *word + 1);
	}
	if (tmp == NULL)
		panic_malloc();
	free(*word);
	*word = tmp;
	return (*word);
}