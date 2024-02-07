/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:37:12 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/07 15:27:44 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"

void	erase_node(t_node **node)
{
	ft_free((void **) &(*node)->word);
	ft_free((void **) &(*node)->left);
	ft_free((void **) &(*node)->newl_ptr);
	ft_free((void **) &(*node)->right);
	ft_free((void **) node);
}
