/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:46:35 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/07 20:32:36 by akeryan          ###   ########.fr       */
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
int	program(t_node *head, t_data *data)
{
	if (!head)
		return (1);
	if (newline_list(head->left) == -1)
		return (-1);
	if (pipeline(head->right, data) == -1)
		return (-1);
	return (0);
}

int	prefix(t_node *node)
{
	if (node == NULL)
		return (1);
	if (redirect(node->left) == -1)
		return (-1);
	if (prefix(node->right) == -1)
		return (-1);
	return (0);
}

int	suffix(t_node *node, t_word_node *head)
{
	if (node == NULL)
		return (1);
	if (redirect(node->left) == -1)
		return (-1);
	if (node->word)
		add_word_back(&head, new_word(node->word));
	if (suffix(node->right, head) == -1)
		return (-1);
	return (0);
}

int	newline_list(t_node *node)
{
	if (node == NULL)
		return (1);
	newline_list(node->left);
	return (0);
}
