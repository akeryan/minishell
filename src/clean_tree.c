/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:51:56 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/27 15:10:16 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grammar.h"
#include <stdlib.h>

void	clean_tree(t_node *root)
{
	if (!root)
		return ;
	if (root->word)
		free(root->word);
	root->word = NULL;
	if (root->left)
		clean_tree(root->left);
	root->left = NULL;
	if (root->newl_ptr)
		clean_tree(root->newl_ptr);
	root->newl_ptr = NULL;
	if (root->right)
		clean_tree(root->right);
	root->right = NULL;
	free(root);
}
