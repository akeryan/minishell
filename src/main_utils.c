/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:41:59 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/08 10:24:15 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "data.h"

t_data	*new_data(void)
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

/**
 * @brief Free malloced memory for t_data
 * @param data Pointer to t_data variable
 * @return 0 - Successful execution
 * @return 1 - Argument is empty
*/
int	free_data(t_data *data)
{
	if (!data)
		return (1);
	if (data->pid_list)
		free_pid_list(data->pid_list);
	if (data->pipe_list)
		free_pipe_list(data->pipe_list);
	return (0);
}

int	free_tree(t_node *head)
{
	(void)head;
	return (0);
}

int	free_all(t_node *tree, t_data *data)
{
	free_tree(tree);
	free_data(data);
	return (0);
}
