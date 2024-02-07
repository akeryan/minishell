/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:45:25 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/07 20:56:47 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

t_data	*new_data(void);
void	free_all(t_node *tree, t_data *data);
void	free_data(t_data *data);
void	free_tree(t_node *head);