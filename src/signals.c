/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:49:09 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/28 19:07:00 by akeryan          ###   ########.fr       */
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
	if (g_signal == 0)
	{
		x++;
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	setup_sigs(void)
{
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
		return (-1);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (-1);
	return (0);
}
