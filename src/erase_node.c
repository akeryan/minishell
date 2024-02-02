/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:37:12 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/02 18:45:06 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"

void	erase_node(t_node **node)
{
	ft_free((void **) &(*node)->word);
	ft_free((void **) &(*node)->left);
	ft_free((void **) &(*node)->newl_ptr);
	ft_free((void **) &(*node)->right);
	ft_free((void **) node);
}
