/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:51:56 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/29 17:32:38 by akeryan          ###   ########.fr       */
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

void	clean_dblptr(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
