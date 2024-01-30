/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:27:16 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/30 15:42:11 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include "execute.h"
#include "word_list.h"
#include "redirect.h"

void	program(t_node *head, t_data *d)
{
	if (head == NULL)
		return ;
	newline_list(head->left);
	pipeline(head->right, d);
}

void	pipeline(t_node *node, t_data *d)
{
	int	pipe_fd[2];

	if (node == NULL)
		return ;
	pipe(pipe_fd);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		ft_printf(2, "%s\n", strerror(errno));
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		ft_printf(2, "%s\n", strerror(errno));
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	command(node->left, d);
	pipeline(node->right, d);
}

void	prefix(t_node *node)
{
	if (node == NULL)
		return ;
	redirect(node->left);
	prefix(node->right);
}

void	suffix(t_node *node, t_word_node *head)
{
	if (node == NULL)
		return ;
	redirect(node->left);
	if (node->word)
		add_word_back(&head, node->word);
	suffix(node->right, head);
}

void redirect(t_node *node)
{
	if (node->redir_type == LESS)
		return redir_read(node->word);
	if (node->redir_type == GREAT)
		return redir_write(node->word);
	if (node->redir_type == DGREAT)
		return redir_append(node->word);
	if (node->redir_type == DLESS)
		return here_doc();//???????
}
//char **newline(t_node *node)
//{

//}
