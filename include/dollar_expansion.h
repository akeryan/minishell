/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:28:16 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/20 16:55:47 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOLLAR_EXPANSION_H
# define DOLLAR_EXPANSION_H

# include "word_list.h"
# include "data.h"

int		func_1(char **current, t_word_node **head);
void	func_2(t_word_node **head, char **current, char **ptr);
int		func_3(char **ptr, t_word_node **head, t_data *data, char **current);
void	func_4(char **ptr, char **current, t_word_node **head);
int		func_5(char **ptr, char **current);
int		func_6(t_word_node **head, char **current);
int		func_7(t_word_node **head);

#endif