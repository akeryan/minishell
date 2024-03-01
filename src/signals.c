/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:49:09 by dabdygal          #+#    #+#             */
/*   Updated: 2024/03/01 20:06:35 by dabdygal         ###   ########.fr       */
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
	write(STDERR_FILENO, "\n", 1);
	if (g_signal != 1)
	{
		x++;
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	g_signal = -1;
}

int	setup_sigs(void)
{
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
		return (-1);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (-1);
	return (0);
}
