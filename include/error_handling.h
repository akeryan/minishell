/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:25 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/02 15:14:49 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# define MSH_NAME	"minishell"
# define ALLOC_ERR	"Failed to allocate memory"
# define PATH_ERR	"command not found"

# include <stdio.h>
# include <string.h>
# include <errno.h>

int		execve_error_msg(char *path, char *cmd_name);
void	error_exit(char *str);
void	panic_malloc(void);
void	panic(char *txt);
void	do_this_1(char *path, int *exit_stat);
void	do_this_2(char *path, int *exit_stat);

#endif