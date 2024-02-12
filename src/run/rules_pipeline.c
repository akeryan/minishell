/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:32:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/12 18:06:55 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "error_handling.h"
#include "rules.h"
#include "data.h"

static int	fork_(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork");
	return (pid);
}

static void	child_process(t_node *node, int *p, int *p_)
{
	if (p_)
	{
		if (dup2(*p_, STDIN_FILENO) == -1)
			error_exit("dup2 in pipeline (p_)");
		if (close(*p_) == -1)
			error_exit("close in pipeline (p_)");
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
}

/**
 * @brief	Implements 'pipeline' node of the parsing tree
 * @param	node Pointer to PIPELINE node	
 * @param	p_ pointer to the reading end of the preceding pipe
*/
void	pipeline(t_node *node, int *p_, t_data *d)
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
		child_process(node, p, p_);
	else if (pid > 0)
	{
		if (node->right)
			if (close(p[1]) == -1)
				error_exit("close in parent");
		pipeline(node->right, &p[0], d);
		waitpid(pid, &status, 0);
		if (!node->right)
			if (WIFEXITED(status))
				d->exit_status = WEXITSTATUS(status);
	}
}
