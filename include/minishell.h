/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:57 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/16 10:52:39 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/** MSH_PROMPT - prompt message */
# define MSH_PROMPT "minishell-1.0$ "
# define MSH_PS2	">"
# define MSH_TMPFIL_PREF "/tmp/minishell_tmp_"

/** EXIT_MSG - exit message */
# define EXIT_MSG "exit\n"

int	echo(const char *argv[]);
int	cd(const char *argv[], char ***envp);
int	pwd(char *argv[]);

#endif
