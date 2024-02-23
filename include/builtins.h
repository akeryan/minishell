/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:08:51 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/23 15:47:28 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		echo(const char *argv[]);
int		cd(const char *argv[], char ***envp);
int		pwd(void);
int		ft_export(char *argv[], char ***envp);
int		unset(char *argv[], char **envp);
int		env(char *argv[], char **envp);
int		ft_exit(char *argv[]);

#endif
