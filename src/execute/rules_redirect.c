/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:54:33 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/06 14:03:58 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "fcntl.h"

int	redirect(t_node *node)
{
	if (node == NULL)
		return (1);
	if (node->redir_type == LESS)
		return (redir_read(node->word));
	if (node->redir_type == GREAT)
		return (redir_write(node->word));
	if (node->redir_type == DGREAT)
		return (redir_append(node->word));
	if (node->redir_type == DLESS)
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
	if (fd_dup2(fd, STDIN_FILENO) == -1)
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
	if (fd_dup2(fd, STDOUT_FILENO) == -1)
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
	if (fd_dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (ft_close(1, fd) == -1)
		return (-1);
	return (0);
}

static int	here_doc(char *file_name)
{
	if (redir_read(file_name) == -1)
		return (-1);
	return (0);
}
