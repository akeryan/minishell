/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:49:09 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/24 13:16:34 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "readline/readline.h"
#include "readline/history.h"

int	g_signal;

void	handle_sigint(int x)
{
	x = 0;
	write(STDERR_FILENO, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
}

int	setup_sigs(void)
{
	struct sigaction	s_sint;

	g_signal = 0;
	s_sint.__sigaction_u.__sa_handler = handle_sigint;
	s_sint.sa_flags = 0;
	s_sint.sa_mask = 0;
	if (sigaction(SIGINT, &s_sint, NULL) < 0)
		return (-1);
	s_sint.__sigaction_u.__sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &s_sint, NULL) < 0)
		return (-1);
	return (0);
}