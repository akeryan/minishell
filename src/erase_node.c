/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:37:12 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/01 15:42:39 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "libft.h"

void	erase_node(t_node **node)
{
	ft_free(&(*node)->word);
	ft_free(&(*node)->left);
	ft_free(&(*node)->newl_ptr);
	ft_free(&(*node)->right);
	ft_free(node);
}
