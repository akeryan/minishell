/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:00:29 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/26 17:08:36 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "print_tree.h"

void	print_tree(t_node *node, int level)
{
	if (!node)
	{
		printf("(null)\n");
		return ;
	}
	if (level != 0)
	{
		printf("\n");
		print_tabs(level);
		printf("{\n");
	}
	print_cases(level, node);
	if (level != 0)
	{
		print_tabs(level);
		printf("}\n");
	}
}
