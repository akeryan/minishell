/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:51:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/20 16:55:11 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "word_list.h"

int	func_6(t_word_node **head, char **current)
{
	add_word_back(head, new_word(*current));
	return (1);
}

int	func_7(t_word_node **head)
{
	add_word_back(head, new_word("$"));
	return (1);
}
