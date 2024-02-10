/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:48:45 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/10 20:55:00 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "error_handling.h"
#include "word_list.h"
#include "libft.h"

t_word_node	*new_empty_word(void)
{
	t_word_node	*new_node;

	new_node = (t_word_node *)malloc(sizeof(t_word_node));
	if (new_node == NULL)
		error_exit("malloc");	
	new_node->word = NULL;
	new_node->next = NULL;
	return (new_node);
}

/**
 * @brief Creates a new t_word_node node and assigns str value to 'word'
 * str is duplicated to avoid double-free error when freeing memory
 * @param str Character string that 'word' attribute to be initialized with
 * @return Newly created node of t_word_node type
 */

t_word_node	*new_word(const char * const str)
{
	t_word_node	*new_node;

	new_node = new_empty_word();
	new_node->word = ft_strdup(str);
	return (new_node);
}

/**
 * @brief Adds node to the end of the list
 * @param head Pointer to the first node of the list
 * @param node Pointer to the node that needs to be added to the list
*/
void	add_word_back(t_word_node ** const head, t_word_node *node)
{
	t_word_node	*temp;
	if (head)
	{
		if (!*head)
			*head = node;
		else
		{
			temp = *head;
			while (temp -> next)
				temp = temp -> next;
			temp -> next = node;
		}
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

/**
 * @brief Counts number of nodes in the list
 * @param head A pointer to the first node of the list
 * @return A number of nodes in the list
*/
int		word_list_len(t_word_node *head)
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
