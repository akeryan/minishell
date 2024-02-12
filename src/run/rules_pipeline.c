/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:32:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/12 12:09:06 by akeryan          ###   ########.fr       */
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
void	pipeline(t_node *node)
{
	int	p[2];
	int	pid_cmd;
	int	pid_pipe;
	int	status_cmd;
	int	status_pipe;

	if (node == NULL)
		return ;
	if (node->right)
	{
		if (pipe(p) == -1)
			error_exit("pipe");
	}
	pid_cmd = fork_();
	if (pid_cmd == 0)
	{
		if (node->right)
		{
			if (dup2(p[1], STDOUT_FILENO) == -1)
				error_exit("dup2 in pipeline");
			if (close(p[0]) == -1)
				error_exit("close in pipeline (child 1)");
			if (close(p[1]) == -1)
				error_exit("close in pipeline (child 1)");
		}
		command(node->left);
		exit(0);
	}
	if (node->right && pid_cmd > 0)
	{
		pid_pipe = fork_();
		if (pid_pipe == 0)
		{
			if (dup2(p[0], STDIN_FILENO) == -1)
				error_exit("dup2 in pipeline (child) 2");
			if (close(p[0]) == -1)
				error_exit("close in pipeline (child 2)");
			if (close(p[1]) == -1)
				error_exit("close in pipeline (child 2)");
			pipeline(node->right);
			exit(0);
		}
		if (close(p[0]) == -1)
			error_exit("close in pipeline (parent - 1)");
		if (close(p[1]) == -1)
			error_exit("close in pipeline (parent - 2)");
	}
	if (pid_cmd > 0)
	{
		waitpid(pid_cmd, &status_cmd, 0);
		if (!node->right)
		{
			if (WIFEXITED(status_cmd))
				exit(WEXITSTATUS(status_cmd));
		}
	}
	if (node->right && pid_pipe > 0)
	{
		waitpid(pid_pipe, &status_pipe, 0);
		if (WIFEXITED(status_pipe))
			exit(WEXITSTATUS(status_pipe));
	}
	//probably first I should check whether the right branch is NULL or not
	//if NULL then I should exit with exit status of left branch,
	//otherwise with exit status of right branch 
}
