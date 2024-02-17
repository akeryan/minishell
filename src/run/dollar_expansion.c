/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:55:06 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/17 16:37:12 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

int	apply_expansions(char **word, char ***env)
{
	tilde_expansion(word, env);
	return (0);
}
