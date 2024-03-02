/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:46:35 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/02 14:29:17 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "data.h"
#include "rules.h"
#include "error_handling.h"
#include "word_list.h"
#include "expansion.h"

extern int	g_signal;

/**
 * @brief Implements 'program' node of the parsing tree
 * @param head Pointer to the root of the tree
 * @param data Pointer to the t_data structure
 * @return 0 - Successful execution;
 * @return -1 - Execution failed;
 * @return 1 - Empty input
*/
int	program(t_node *root, t_data *data)
{
	int	state;
	int	old;

	old = g_signal;
	if (old < 0)
		data->exit_status = 1;
	g_signal = 1;
	if (root == NULL)
		return (-1);
	newline_list(root->newl_ptr);
	state = pipeline(root->left, NULL, data);
	//printf("state from pipeline(): %d\n", state);
	g_signal = old;
	return (state);
}

void	prefix(t_node *node, t_data *data)
{
	if (node == NULL)
		return ;
	redirect(node->left, data);
	prefix(node->right, data);
}

void	suffix(t_node *node, t_word_node **args, t_data *data)
{
	if (node == NULL)
		return ;
	redirect(node->left, data);
	if (node->word)
	{
		apply_expansions(&node->word, data);
		add_word_back(args, new_word(node->word));
	}
	suffix(node->right, args, data);
}

int	newline_list(t_node *node)
{
	if (node == NULL)
		return (1);
	newline_list(node->newl_ptr);
	return (0);
}
