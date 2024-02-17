/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:19:10 by akeryan           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/17 17:00:49 by akeryan          ###   ########.fr       */
=======
/*   Updated: 2024/02/17 13:15:14 by akeryan          ###   ########.fr       */
>>>>>>> 9585be07d50108eeacaae09b0c0a88e884735ded
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include <stdbool.h>

int		apply_expansions(char **word, char ***env);
void	tilde_expansion(char **word, char ***env);
<<<<<<< HEAD
=======
void	dollar_expansion(char **word, char ***env);
>>>>>>> 9585be07d50108eeacaae09b0c0a88e884735ded
bool	is_quoted(const char *str, const char *target);
char	*is_there_unquoted_slash(char *word);
char	*ft_getenv(char *word, char **env);
int		does_dir_exist(const char *path);
bool	is_single_quoted(const char *str, const char *target);

#endif