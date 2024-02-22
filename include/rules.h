/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:47:48 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/22 22:15:33 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "data.h"
# include "word_list.h"
# include "ft_printf.h"

int		program(t_node *head, t_data *data);
void	pipeline(t_node *node, int *p_, t_data *data);
int		command(t_node *node, t_data *data);
void	prefix(t_node *node, t_data *data);
void	suffix(t_node *node, t_word_node **args, t_data *data);
int		redirect(t_node *node, t_data *data);
int		newline_list(t_node *node);
char	*get_cmd_path(char *cmd);

#endif