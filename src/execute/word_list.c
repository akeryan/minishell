/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:48:45 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/29 15:48:57 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <word_list.h>
#include <stdlib.h>
#include "libft.h"

t_word_node	*new_empty_word(void)
{
	t_word_node	*new_node;

	new_node = (t_word_node *)malloc(sizeof(t_word_node));
	{
		//ft_printf(2, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	new_node->word = NULL;
	new_node->next = NULL;
}

/**
 * @brief Creates a new t_word_node node and assigns str value to 'word'
 * str is duplicated to avoid double-free error when freeing memory
 * @param str Character string that 'word' attribute to be initialized with
 * @return Newly created node of t_word_node type
 */

t_word_node	*new_word(char *str)
{
	t_word_node	*new_node;

	new_node = new_empty_word();
	new_node->word = ft_strdup(str);
	return (new_node);
}

/**
 * @brief Adds node to the beginning of the list
 * @param head Pointer to the first node of the list
 * @param node Pointer to the node that needs to be added to the list
*/
void	add_word_front(t_word_node **head, t_word_node *node)
{
	if (head)
	{
		if (*head && node)
			node->next = *head;
		*head = node;
	}
}

/**
 * @brief The memory occupied by the linked list of t_pid_node type
 * @param head A pointer to the head of the linked list
*/
void	free_word_list(t_word_node *head)
{
	t_word_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->word);
		free(tmp);
	}
}
