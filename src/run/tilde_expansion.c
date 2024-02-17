/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:10:13 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/17 13:23:04 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "error_handling.h"
#include "expansion.h"
#include "data.h"

static void	init_vars(t_tilde_vars *v, char ***env)
{
	v->usr_name = ft_getenv("USER", *env);
	if (!v->usr_name)
		panic("Error: USER is unset");
	v->home_dir = ft_getenv("HOME", *env);
	if (!v->home_dir)
		panic("Error: HOME is unset");
	v->usrs_dir = ft_strdup(v->home_dir, ft_strlen(v->home_dir) - \
		ft_strlen(v->usr_name));
}

static char	*get_expansion(t_tilde_vars *v, char **word)
{
	char	*ptr;

	if (!v->slash)
	{
		if (*(*word + 1) == '\0')
			ptr = ft_strdup(v->home_dir, ft_strlen(v->home_dir));
		else
			ptr = ft_strjoin(v->usrs_dir, *word + 1);
	}
	else
	{
		if (*(*word + 1) == '/')
			ptr = ft_strjoin(v->home_dir, *word + 1);
		else
			ptr = ft_strjoin(v->usrs_dir, *word + 1);
	}
	free(v->usrs_dir);
	return (ptr);
}

void	tilde_expansion(char **word, char ***env)
{
	t_tilde_vars	v;
	char			*tmp;

	if (!word)
		return ;
	if (*word[0] != '~')
		return ;
	init_vars(&v, env);
	v.slash = is_there_unquoted_slash(*word);
	tmp = get_expansion(&v, word);
	if (tmp == NULL)
		panic_malloc();
	free(*word);
	*word = tmp;
}

int	apply_expansions(char **word, char ***env)
{
	tilde_expansion(word, env);
	return (0);
}
