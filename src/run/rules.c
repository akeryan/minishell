/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:46:35 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/11 17:54:46 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "rules.h"
#include "error_handling.h"
#include "word_list.h"

/**
 * @brief Implements 'program' node of the parsing tree
 * @param head Pointer to the root of the tree
 * @param data Pointer to the t_data structure
 * @return 0 - Successful execution;
 * @return -1 - Execution failed;
 * @return 1 - Empty input
*/
int	program(t_node *head)
{
	newline_list(head->newl_ptr);
	pipeline(head->left);
	return (0);
}

void	prefix(t_node *node)
{
	if (node == NULL)
		return ;
	redirect(node->left);
	prefix(node->right);
}

void	suffix(t_node *node, t_word_node **args)
{
	if (node == NULL)
		return ;
	redirect(node->left);
	if (node->word)
		add_word_back(args, new_word(node->word));
	suffix(node->right, args);
}

int	newline_list(t_node *node)
{
	if (node == NULL)
		return (1);
	newline_list(node->newl_ptr);
	return (0);
}
