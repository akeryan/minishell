/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:26:44 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/29 15:52:15 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_LIST_H
# define WORD_LIST_H

// ---------------- DATA STRUCTURES -----------------------
/**
 * @brief Represents a node in a linkded list for storing WORDs 
*/
typedef struct s_word_node
{
	char				*word;
	struct s_word_node	*next;
}	t_word_node;

// ---------------- PROTOTYPES ----------------------------
/**
 * @brief Creates a new node of type t_word_node and initializes its parameters
 * with default values: word=NULL, next=NULL;
 * @return	A pointer to the newly created node.
*/
t_word_node	*new_empty_word(void);

/**
 * @brief Creates a new node of type t_word_node and initializes
 * the 'word' parameter with str
 * @param str A string of valid characters that a word to be initialized with
 * @return	A pointer to the newly created node. If memory allocation fails
 * the program exits with EXIT_FAILURE and doesn't return 
*/
t_word_node	*new_word(char *str);

/**
 * @brief Adds node to the beginning of the list
 * @param head Pointer to the first node of the list
 * @param node Pointer to the node that needs to be added to the list
*/
void		add_word_back(t_word_node **head, t_word_node *word_node);

/**
 * @brief Frees up the memory occupied by the linked list of t_word_node
 * @param head A pointer to the head of the linked list
*/
void		free_word_list(t_word_node *head);

#endif