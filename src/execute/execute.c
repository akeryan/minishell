/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:27:16 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/31 19:57:44 by akeryan          ###   ########.fr       */
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
	pipeline(head->right, NULL, d);
}

void	pipeline(t_node *node, int _pipe[2], t_data *d)
{
	int	pipe_[2];

	if (node == NULL)
		return ;
	if (_pipe)
		if (dup2(_pipe[0], STDIN_FILENO) == -1)
			ft_printf(2, "%s\n", strerror(errno));
	if (node->right)
	{
		pipe(pipe_);
		if (dup2(pipe_[1], STDOUT_FILENO) == -1)
			ft_printf(2, "%s\n", strerror(errno));
		close(pipe_[0]);
		close(pipe_[1]);
	}
	command(node->left, d);
	if (node->right)
		pipeline(node->right, pipe_, d);
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

void newline_list(t_node *node)
{
	if (node == NULL)
		return ;
	newline_list(node->left);
}
