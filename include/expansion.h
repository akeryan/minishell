/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:19:10 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/17 13:22:08 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include <stdbool.h>

int		apply_expansions(char **word, char ***env);
void	tilde_expansion(char **word, char ***env);
bool	is_quoted(const char *str, const char *target);
char	*is_there_unquoted_slash(char *word);
char	*ft_getenv(char *word, char **env);

#endif