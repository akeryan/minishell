/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:32:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/10 17:06:56 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
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

	if (pipe(p) == -1)
		error_exit("pipe");
	if (fork_() == 0)
	{
		dup2(p[1], STDOUT_FILENO);
		close(p[0]);
		close(p[1]);
		run_cmd(node->left);
	}
	if (fork_() == 0)
	{
		dup2(p[0], STDIN_FILENO);
		close(p[0]);
		close(p[1]);
		run_cmd(node->right);
	}
	close(p[0]);
	close(p[1]);
	wait(NULL);
	wait(NULL);
	//probably first I should check whether the right branch is NULL or not
	//if NULL then I should exit with exit status of left branch,
	//otherwise with exit status of right branch 
}
