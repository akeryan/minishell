/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:10:13 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/01 12:35:46 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "error_handling.h"
#include "expansion.h"
#include "data.h"

static void	init_vars(t_tilde_vars *v, char ***env)
{
	v->usr_name = ft_getenv_aram("USER", *env);
	if (!v->usr_name)
		panic("Error: USER is unset");
	v->home_dir = ft_getenv_aram("HOME", *env);
	if (!v->home_dir)
		panic("Error: HOME is unset");
	v->usrs_dir = ft_substr(v->home_dir, 0, ft_strlen(v->home_dir) - \
		ft_strlen(v->usr_name));
}

static char	*no_slash_expansion(t_tilde_vars *v, char **word)
{
	char	*ptr;

	if (*(*word + 1) == '\0')
		ptr = ft_strdup(v->home_dir);
	else
	{
		ptr = ft_strjoin(v->usrs_dir, *word + 1);
		if (!ptr)
			panic_malloc();
		if (!does_dir_exist(ptr))
		{
			ft_free((void **)&ptr);
			ptr = ft_strdup(*word);
		}
		else
			ptr = ft_strjoin(v->usrs_dir, *word + 1);
	}
	if (!ptr)
		panic_malloc();
	return (ptr);
}

static char	*with_slash_expansion(t_tilde_vars *v, char **word)
{
	char	*ptr;
	char	*ptr2;

	if (*(*word + 1) == '/')
		ptr = ft_strjoin(v->home_dir, *word + 1);
	else
	{
		ptr2 = ft_strchr(*word, '/');
		ptr = ft_substr(*word + 1, 0, ft_strlen(*word) - ft_strlen(ptr2) - 1);
		if (!ptr)
			panic_malloc();
		ptr2 = ft_strjoin(v->usrs_dir, ptr);
		if (!ptr2)
			panic_malloc();
		if (!does_dir_exist(ptr2))
			ptr = ft_strdup(*word);
		else
			ptr = ft_strjoin(v->usrs_dir, *word + 1);
		ft_free((void **)&ptr2);
	}
	if (!ptr)
		panic_malloc();
	return (ptr);
}

static char	*get_expansion(t_tilde_vars *v, char **word)
{
	char	*ptr;

	if (!v->slash)
		ptr = no_slash_expansion(v, word);
	else
		ptr = with_slash_expansion(v, word);
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
	ft_free((void **)&v.usrs_dir);
	ft_free((void **)word);
	*word = tmp;
}
