/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:47:48 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/08 09:30:07 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "data.h"
# include "word_list.h"

int		program(t_node *head, t_data *data);
int		pipeline(t_node *node, t_data *d);
int		command(const t_node *node, t_data *d);
int		prefix(t_node *node);
int		suffix(t_node *node, t_word_node *head);
int		redirect(t_node *node);
int		newline_list(t_node *node);

#endif