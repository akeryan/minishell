/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:55:45 by dabdygal          #+#    #+#             */
/*   Updated: 2024/01/15 17:12:06 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include "readline/readline.h"

/**
 * @brief readline() and output as a line struct with cursor.
 * @details ft_readline function uses readline() with \p prompt as prompt and 
 * stores the read string as "input" of structure "t_line", "cursor" is set as
 * "input".
 * @param prompt A string to be displayed at terminal as prompt.
 * @return Returns struct t_line. If EOF or error encountered "input" and
 * "cursor" members set as NULL.
*/
t_line	ft_readline(const char *prompt)
{
	t_line	line;

	line.input = readline(prompt);
	line.cursor = line.input;
	return (line);
}
