/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:45:25 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/24 16:35:31 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_UTILS_H
# define MAIN_UTILS_H

# include "data.h"

int		free_all(t_node *tree);
int		free_tree(t_node *head);
void	print_array_of_strings(char **arr);

#endif