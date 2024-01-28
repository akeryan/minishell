/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:59:14 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/28 11:55:52 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
# include <errno.h>
#include "pid_list.h"

t_pid_node *create_node(int value)
{
	t_pid_node	*new_node;

	new_node = (t_pid_node *)malloc(sizeof(t_pid_node));
	if (!new_node)
	{
		ft_printf(2, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}

void free_pid_list (t_pid_node *head)
{

}