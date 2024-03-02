/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:47:48 by akeryan           #+#    #+#             */
/*   Updated: 2024/03/02 14:56:59 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H

# include "data.h"
# include "word_list.h"
# include "ft_printf.h"

int		program(t_node *head, t_data *data);
int		pipeline(t_node *node, int *p_, t_data *data);
int		command(t_node *node, t_data *data);
void	prefix(t_node *node, t_data *data);
void	suffix(t_node *node, t_word_node **args, t_data *data);
int		redirect(t_node *node, t_data *data);
void	redir_read(char *file_name, t_data *data);
void	redir_write(char *file_name, t_data *data);
void	redir_append(char *file_name, t_data *data);
void	here_doc(char *file_name, t_data *data);
int		newline_list(t_node *node);
char	*get_cmd_path(char *cmd, char **envp);
int		run_exit(char **argv, t_data *data);
int		run_builtin(char *cmd, char **argv, t_data *data);
int		get_cmd_from_args(char ***argv, t_node *node);
void	ft_cleaner(t_data *d, t_word_node *arglist, char **argv, int status);
int		cmd_func_1(char ***argv, t_node *node, t_data *data);
void	cmd_func_2(int *state, t_node *node, char **argv, t_data *data);

#endif