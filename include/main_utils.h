/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:45:25 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/07 21:34:25 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_UTILS_H
# define MAIN_UTILS_H

# include "data.h"

t_data	*new_data(void);
int		free_all(t_node *tree, t_data *data);
//int		free_data(t_data *data);
int		free_tree(t_node *head);

#endif