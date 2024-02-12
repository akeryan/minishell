/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:32:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/12 15:37:26 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "error_handling.h"
#include "rules.h"
#include "data.h"

int	fork_(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork");
	return (pid);
}

/**
 * @brief	Implements 'pipeline' node of the parsing tree
 * @param	node Pointer to PIPELINE node	
*/
void	pipeline(t_node *node, int *_p)
{
	int	p[2];
	int	pid;
	int	status;

	if (node == NULL)
		return ;
	if (node->right)
	{
		if (pipe(p) == -1)
			error_exit("pipe");
	}
	pid = fork_();
	if (pid == -1)
		error_exit("fork");
	else if (pid == 0)
	{
		if (_p)
		{
			if (dup2(_p[0], STDIN_FILENO) == -1)
				error_exit("dup2 in pipeline (-p)");
			if (close(_p[0]) == -1)
				error_exit("close in pipeline (_p)");
		}
		if (node->right)
		{
			if (dup2(p[1], STDOUT_FILENO) == -1)
				error_exit("dup2 in pipeline");
			if (close(p[0]) == -1)
				error_exit("close in child (1)");
			if (close(p[1]) == -1)
				error_exit("close in child (2)");
		}
		command(node->left);
		exit(42);
	}
	else if (pid > 0)
	{
		if (node->right)
			if (close(p[1]) == -1)
				error_exit("close in parent");
		pipeline(node->right, p);
		waitpid(pid, &status, 0);
	}
}
