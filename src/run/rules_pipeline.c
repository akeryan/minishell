/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:32:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/11 18:21:08 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libft.h"
#include "error_handling.h"
#include "rules.h"
#include "data.h"

int fork_(void)
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
	int p[2];
	int pid1;
	int pid2;

	if (node == NULL)
		return ;
	if (node->right)
	{
		if (pipe(p) == -1)
			error_exit("pipe");
	}
	pid1 = fork_();
	if (pid1 == 0)
	{
		if (node->right)
		{
			if (dup2(p[1], STDOUT_FILENO) == -1)
				error_exit("dup2 in pipeline");
			if (close(p[0]) == -1) error_exit("close in pipeline (child 1)");
			if (close(p[1]) == -1) error_exit("close in pipeline (child 1)");
		}
		command(node->left);
		exit(0);
	}
	
	if (node->right && pid1 > 0)
	{
		pid2 = fork_();
		if (pid2 == 0)
		{
			if (dup2(p[0], STDIN_FILENO) == -1)
				error_exit("dup2 in pipeline (child) 2");
			if (close(p[0]) == -1) error_exit("close in pipeline (child 2)");
			if (close(p[1]) == -1) error_exit("close in pipeline (child 2)");
			pipeline(node->right);
			exit(0);
		}
		if (close(p[0]) == -1) error_exit("close in pipeline (parent - 1)");
		if (close(p[1]) == -1) error_exit("close in pipeline (parent - 2)");
	}
	if (pid1 > 0)
		waitpid(pid1, NULL, 0);
	if (node->right && pid2 > 0)
		waitpid(pid2, NULL, 0);
	//probably first I should check whether the right branch is NULL or not
	//if NULL then I should exit with exit status of left branch,
	//otherwise with exit status of right branch 
}
