/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:54:33 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/07 20:04:51 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "rules_utils.h"
#include "data.h"

static int	redir_read(char *file_name);
static int	redir_write(char *file_name);
static int	redir_append(char *file_name);
static int	here_doc(char *file_name);

int	redirect(t_node *node)
{
	if (node == NULL)
		return (1);
	if (node->token_type == LESS)
		return (redir_read(node->word));
	if (node->token_type == GREAT)
		return (redir_write(node->word));
	if (node->token_type == DGREAT)
		return (redir_append(node->word));
	if (node->token_type == DLESS)
		return (here_doc(node->word));
	return (1);
}

static int	redir_read(char *file_name)
{
	int	fd;

	if (!file_name)
		return (1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("open: ");
		return (-1);
	}
	if (ft_dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	if (ft_close(1, fd) == -1)
		return (-1);
	return (0);
}

static int	redir_write(char *file_name)
{
	int	fd;

	if (!file_name)
		return (1);
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		perror("open: ");
		return (-1);
	}
	if (ft_dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (ft_close(1, fd) == -1)
		return (-1);
	return (0);
}

static int	redir_append(char *file_name)
{
	int	fd;

	if (!file_name)
		return (1);
	fd = open(file_name, O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
	{
		perror("open: ");
		return (-1);
	}
	if (ft_dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (ft_close(1, fd) == -1)
		return (-1);
	return (0);
}

static int	here_doc(char *file_name)
{
	int	output;

	output = redir_read(file_name);
	if (unlink(file_name) == -1)
		perror("here_doc: ");
	if (output == -1)
		return (-1);
	return (0);
}
