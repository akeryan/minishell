/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:03:09 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/29 19:04:05 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* GNU bash, version 3.2.57(1)-release (x86_64-apple-darwin19)
Copyright (C) 2007 Free Software Foundation, Inc. */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "node.h"
# include "pid_list.h"
# include "pipe_list.h"

typedef struct s_data
{
	char		**env;
	t_pid_node	*pid_list;
	t_pipe_node	*pipe_list;
}	t_data;

void	command(const t_node *node, t_data *d);
void	redir_read(char *file_name);
void	redir_write(char *file_name);
void	redir_append(char *file_name);

#endif