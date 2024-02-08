/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:28:57 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/08 18:50:14 by akeryan          ###   ########.fr       */
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

# include "data.h"

int	run_cmd(t_node *root);

#endif
