/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_list_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:30:33 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/19 17:31:40 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "error_handling.h"
#include "word_list.h"
#include "libft.h"

/**
 * @brief Counts number of nodes in the list
 * @param head A pointer to the first node of the list
 * @return A number of nodes in the list
*/
int	word_list_len(t_word_node *head)
{
	t_word_node		*tmp;
	unsigned int	len;

	if (head == NULL)
		return (0);
	tmp = head;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
