/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/10 16:31:22 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "rules.h"
#include "word_list.h"
#include "libft.h"
#include "error_handling.h"
#include "free.h"


/**
 * @brief Executes command with execve system utility
 * @param cmd_name Name of the command to be executed
 * @param argv Arguments of the command
*/
static int	ft_execve(char *cmd_name, char **argv)
{
	char	*path;

	if (!ft_strchr(cmd_name, '/'))
		path = get_cmd_path(cmd_name);
	else
		path = cmd_name;
	if (execve(path, argv, NULL) == -1)
		execve_error_msg(path);
	free(path);
	return (-1);
}

/**
 * @brief Converts the t_word_node list to an array of strings
 * @param head A pointer to the first node of the list 
 * @return A pointer to the array of strings
*/
static char	**list_to_array(t_word_node *head)
{
	char		**arr;
	int			len;
	int			i;

	len = word_list_len(head);
	arr = (char **)malloc((len + 1) * sizeof(char *));
	if (arr == NULL)
	{
		perror("malloc (list_to_array): ");
		return (NULL);
	}
	i = 0;
	while (head)
	{
		arr[i] = ft_strdup(head->word);
		if (arr[i] == NULL)
		{
			while (--i >= 0)
				free(arr[i]);
			return (NULL);
		}
		head = head->next;
		i++;
	}
	return (arr[i] = NULL, arr);
}

/**
 * @brief Implements 'command' node of the parsing tree
 * @param node Pointer to the COMMAND node
 * @param d Pointer to the t_data structure
 * @return 0: Successful execution;
 * @return -1: Execution failed;
*/
void	command(t_node *const node)
{
	t_word_node	*args_list;
	char		**argv;

	args_list = NULL;
	argv = NULL;
	prefix(node->left);
	suffix(node->right, args_list);
	if (args_list != NULL)
		argv = list_to_array(args_list);
	free_word_list(args_list);
	ft_execve(node->word, argv);
	free_split(argv);
}
