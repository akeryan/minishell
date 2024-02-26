/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:57:01 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/26 17:11:58 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_TREE_H
# define PRINT_TREE_H

# include "data.h"

char	*token_type_to_a(t_token_type type);
char	*node_type_to_a(t_node_type	type);
void	print_tabs(int level);
char	*str_or_null(char *str);
void	print_cases(int level, t_node *node);
void	print_tree(t_node *node, int level);

#endif