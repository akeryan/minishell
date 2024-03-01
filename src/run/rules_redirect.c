/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:54:33 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/01 19:44:16 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "error_handling.h"
#include "expansion.h"
#include "data.h"
#include "get_next_line.h"
#include "libft.h"

void	here_doc(char *file_name, t_data *data);

void	redir_read(char *file_name, t_data *data)
{
	int	fd;

	if (!file_name)
		return ;
	data->less_fd = dup(STDIN_FILENO);
	if (data->less_fd == -1)
		panic("dup in redir_reader()");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "minishell: %s: No such file or directory\n", file_name);
		return ;
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		error_exit("dup2");
	}
	if (close(fd) == -1)
		error_exit("close");
}

void	redir_write(char *file_name, t_data *data)
{
	int	fd;

	if (!file_name)
		return ;
	data->great_fd = dup(STDOUT_FILENO);
	if (data->great_fd == -1)
		panic("dup in redir_write");
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
		error_exit("open");
	if (dup2(fd, STDOUT_FILENO) == -1)
		error_exit("dup2");
	if (close(fd) == -1)
		error_exit("close");
}

void	redir_append(char *file_name, t_data *data)
{
	int	fd;

	if (!file_name)
		return ;
	data->great_fd = dup(STDOUT_FILENO);
	if (data->great_fd == -1)
		panic("dup in redir_write");
	fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		error_exit("open");
	if (dup2(fd, STDOUT_FILENO) == -1)
		error_exit("dup2");
	if (close(fd) == -1)
		error_exit("close");
}

void	redirect(t_node *node, t_data *data)
{
	if (node == NULL)
		return ;
	apply_expansions(&node->word, data);
	if (node->token_type == LESS)
		redir_read(node->word, data);
	else if (node->token_type == GREAT)
		redir_write(node->word, data);
	else if (node->token_type == DGREAT)
		redir_append(node->word, data);
	else if (node->token_type == DLESS)
		here_doc(node->word, data);
}
