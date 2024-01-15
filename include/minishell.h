/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:57 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/15 17:05:39 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/** MSH_PROMPT - prompt message */
# define MSH_PROMPT "minishell-1.0$ "

/** EXIT_MSG - exit message */
# define EXIT_MSG "\nexit\n"

/** A command line with a cursor, made for succesive tokenizing function */
typedef struct s_line
{
	char	*input;
	char	*cursor;
}	t_line;

t_line	ft_readline(const char *prompt);

#endif
