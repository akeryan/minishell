/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:03:09 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/07 21:24:03 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* GNU bash, version 3.2.57(1)-release (x86_64-apple-darwin19)
Copyright (C) 2007 Free Software Foundation, Inc. */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "data.h"

int		create_pipes(t_node *head, t_data *d);
char	*get_cmd_path(char *cmd);

#endif