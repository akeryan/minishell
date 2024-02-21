/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:57 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/21 14:38:56 by dabdygal         ###   ########.fr       */
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
int	pwd(void);
int	ft_export(char *argv[], char ***envp);
int	export_print(char **envp);
int	unset(char *argv[], char **envp);
int	env(char *argv[], char **envp);

#endif
