/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:55:06 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/17 20:33:57 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "libft.h"
#include "data.h"

void	dollar_expansion(char **word, char ***env)
{
	char			*ptr;
	char			*ptr2;
	char			*word_;

	if (!word)
		return ;
	ptr = ft_strchr(*word, '$');
	if (!ptr)
		return ;
	if (is_single_quoted(*word, ptr))
		return ;
	dollar_init(&d);
	if (ptr != *word)
	


	
	ptr2 = ft_strchr(*word, '"');	
	if (ptr2)
	{
	}
	else
	{
		if (*(ptr + 1) == '{')
		{

		}
		else{
			if (ptr > *word)
			{

			}
			else
			{
				word_ = ft_strdup(*word + 1, ft_strlen(*word + 1));
			}
		}
	}	
	

}

int	apply_expansions(char **word, char ***env)
{
	tilde_expansion(word, env);
	return (0);
}
