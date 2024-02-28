/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:31:55 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/28 19:07:26 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "word_list.h"
#include "libft.h"
#include "data.h"

void	print_array_of_strings(char **arr)
{
	if (!arr)
		return ;
	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}
}

/**
 * @brief Allocates and coppies **str
*/
char	**ft_strdup2(char **str)
{
	char	**out;
	int		i;

	i = -1;
	while (str[++i])
		;
	out = (char **)malloc((++i + 1) * sizeof(char *));
	i = -1;
	while (str[++i])
	{
		out[i] = ft_strdup(str[i]);
		if (out[i] == NULL)
		{
			while (--i >= 0)
				free(out[i]);
			free(out);
			return (NULL);
		}
	}
	out[i] = NULL;
	return (out);
}

/**
 * @brief Converts the t_word_node list to an array of strings
 * @param head A pointer to the first node of the list 
 * @return A pointer to the array of strings
*/
char	**list_to_array(t_word_node *head, char *cmd_name)
{
	char		**argv;
	int			len;
	int			i;

	if (!cmd_name)
		return (NULL);
	len = word_list_len(head);
	argv = (char **)malloc((len + 2) * sizeof(char *));
	if (argv == NULL)
		return (NULL);
	i = 1;
	while (head)
	{
		argv[i] = ft_strdup(head->word);
		if (argv[i] == NULL)
		{
			while (--i >= 0)
				free(argv[i]);
			return (NULL);
		}
		head = head->next;
		i++;
	}
	return (argv[0] = ft_strdup(cmd_name), argv[i] = NULL, argv);
}

void	process_signals(int status, t_data *d)
{
	int	termsig;

	if (WIFEXITED(status))
		d->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		termsig = WTERMSIG(status);
		if (termsig == SIGINT)
			d->exit_status = 130;
		else if (termsig == SIGQUIT)
		{
			printf("Quit: 3\n");
			d->exit_status = 131;
		}
	}
}
