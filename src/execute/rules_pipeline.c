/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:32:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/04 20:45:37 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules_utils.h"
#include "data.h"

/**
 * @brief	Implements 'pipeline' node of the parsing tree
 * @param	node Pointer to PIPELINE node	
 * @param	d Pointer to t_data structure
 * @return	0 - Successful execution;
 * @return	1 - Empty argument(s);
 * @return	-1 - Execution failed;
*/
int	pipeline(t_node *node, t_data *d)
{
	static t_pipe_node	*pipe;

	if (!node || !d)
		return (1);
	else if (node->node_type == PROGRAM)
		pipe = d->pipe_list;
	if (pipe->prev)
		if (ft_dup2(pipe->prev->fd[0], STDIN_FILENO) == -1)
			return (-1);
	if (node->right)
	{
		if (ft_dup2(pipe->fd[1], STDOUT_FILENO) == -1)
			return (-1);
		if (ft_close(2, pipe->fd[0], pipe->fd[1]) == -1)
			return (-1);
	}
	if (command(node->left, d) == -1)
		return (-1);
	if (node->right)
	{
		pipe = pipe->next;
		if (pipeline(node->right, d) == -1)
			return (-1);
	}
	return (0);
}
