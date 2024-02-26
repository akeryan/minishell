/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:32:04 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/26 14:57:30 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "error_handling.h"
#include "rules.h"
#include "data.h"

bool	check_if_in_parent(int *p_, char *cmd)
{
	if (p_ == NULL && cmd)
	{
		if (ft_strcmp(cmd, "cd") == 0 || \
				ft_strcmp(cmd, "export") == 0 || \
				ft_strcmp(cmd, "unset") == 0 || \
				ft_strcmp(cmd, "exit") == 0 \
			)
			return (true);
	}
	return (false);
}

static void	child_process(t_node *node, int *p, int *p_, t_data *d)
{
	int	status;

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
	status = command(node->left, d);
	if (!check_if_in_parent(p_, node->left->word))
		exit(status);
	else if (!node->right)
		d->exit_status = status;
}

static void	process_signals(int status, t_data *d)
{
	int	termsig;

	if (WIFEXITED(status))
		d->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		termsig = WTERMSIG(status);
		if (termsig == SIGINT)
			d->exit_status = 130;
		else if (termsig == SIGQUIT)
		{
			printf("Quit: 3\n");
			d->exit_status = 131;
		}
	}
}

static void	run_cmd_in_child(t_node *node, int *p, int *p_, t_data *d)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
		error_exit("fork");
	if (pid == -1)
		error_exit("fork");
	else if (pid == 0)
		child_process(node, p, p_, d);
	else if (pid > 0)
	{
		if (node->right && close(p[1]) == -1)
			error_exit("close in parent");
		pipeline(node->right, &p[0], d);
		if (node->right && close(p[0]) == -1)
			error_exit("close in parent");
		if (waitpid(pid, &status, 0) == -1)
			d->exit_status = 130;
		if (!node->right)
			process_signals(status, d);
	}
}

/**
 * @brief	Implements 'pipeline' node of the parsing tree
 * @param	node Pointer to PIPELINE node	
 * @param	p_ pointer to the reading end of the preceding pipe
*/
void	pipeline(t_node *node, int *p_, t_data *d)
{
	int	p[2];

	if (node == NULL)
		return ;
	if (node->right)
		if (pipe(p) == -1)
			error_exit("pipe");
	if (check_if_in_parent(p_, node->left->word))
	{
		child_process(node, p, p_, d);
		pipeline(node->right, &p[0], d);
	}
	else
		run_cmd_in_child(node, p, p_, d);
}
