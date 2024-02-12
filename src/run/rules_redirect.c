/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:54:33 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/11 19:11:39 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "error_handling.h"
#include "data.h"

static void	redir_read(char *file_name)
{
	int	fd;

	if (!file_name)
		return ;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_exit("open");
	if (dup2(fd, STDIN_FILENO) == -1)
		error_exit("dup2");
	if (close(fd) == -1)
		error_exit("close");
}

static void	redir_write(char *file_name)
{
	int	fd;

	if (!file_name)
		return ;
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		error_exit("open");
	if (dup2(fd, STDOUT_FILENO) == -1)
		error_exit("dupe2");
	if (close(fd) == -1)
		error_exit("close");
}

static void	redir_append(char *file_name)
{
	int	fd;

	if (!file_name)
		return ;
	fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		error_exit("open");
	if (dup2(fd, STDOUT_FILENO) == -1)
		error_exit("dup2");
	if (close(fd) == -1)
		error_exit("close");
}

static void	here_doc(char *file_name)
{
	redir_read(file_name);
	if (unlink(file_name) == -1)
		error_exit("unlink");
}

void	redirect(t_node *node)
{
	if (node == NULL)
		return ;
	if (node->token_type == LESS)
		redir_read(node->word);
	else if (node->token_type == GREAT)
		redir_write(node->word);
	else if (node->token_type == DGREAT)
		redir_append(node->word);
	else if (node->token_type == DLESS)
		here_doc(node->word);
}
