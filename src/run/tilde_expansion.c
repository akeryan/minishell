/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:10:13 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/16 18:15:46 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "error_handling.h"
#include "expansion.h"

char	*tilde_expansion(char **word, char ***env)
{
	char	*slash;
	char	*usr_name;
	char	*usrs_dir;
	char	*tmp;
	char	*home_dir;
	
	if (!word)
		return (NULL);
	if (*word[0] != '~')
		return (NULL);

	usr_name = ft_getenv("USER", *env);
	if (!usr_name)
	{
		ft_printf(2, "Error: USER is unset\n");
		exit(1);
	}
	printf("usr_name: %s\n", usr_name);
	home_dir = ft_getenv("HOME", *env);
	if (!home_dir)
	{
		ft_printf(2, "Error: HOME is unset\n");
		exit(1);
	}
	printf("home_dir: %s\n", home_dir);
	usrs_dir = ft_strdup(home_dir, ft_strlen(home_dir) - ft_strlen(usr_name));
	printf("usrs_dir: %s\n", usrs_dir);
	slash = is_there_unquoted_slash(*word);
	if (!slash)
	{
		if (*(*word + 1) == '\0')
			//tmp = ft_strjoin(usrs_dir, usr_name);
			tmp = ft_strdup(home_dir, ft_strlen(home_dir));
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
	free(usrs_dir);
	if (tmp == NULL)
		//panic_malloc();
		printf("error");
	free(*word);
	*word = tmp;
	return (*word);
}

int	apply_expansions(char **word, char ***env)
{
	printf("Inside apply_expansions()\n");
	tilde_expansion(word, env);
	return (0);
}
