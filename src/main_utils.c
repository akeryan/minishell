/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:41:59 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/28 13:55:48 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "data.h"

int	free_tree(t_node *head)
{
	(void)head;
	return (0);
}

int	free_all(t_node *tree)
{
	free_tree(tree);
	return (0);
}
