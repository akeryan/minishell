/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:41:59 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/07 21:00:47 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "data.h"
#include "main_utils.h"

t_data *new_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
	{
		perror("malloc: ");
		return (NULL);
	}
	data->pid_list = NULL;
	data->pipe_list = NULL;
	return (data);
}

void free_all(t_node *tree, t_data *data)
{
	free_tree(tree);
	free_data(data);
}

void free_data(t_data *data)
{
	free_pid_list(data->pid_list);
	free_pipe_list(data->pipe_list);
}

void free_tree(t_node *head)
{
	(void)head;
	return ;
}