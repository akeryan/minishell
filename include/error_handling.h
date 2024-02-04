/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:25 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/04 12:27:54 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#define MSH_NAME	"minishell"
#define ALLOC_ERR	"Failed to allocate memory"

#include <string.h>
#include <errno.h>

void	execve_error_msg(char *cmd_name);
void	malloc_error_msg(void);

#endif