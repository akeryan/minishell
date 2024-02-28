/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:45:25 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/28 13:52:58 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_UTILS_H
# define MAIN_UTILS_H

# include "data.h"
# include "word_list.h"

char		**list_to_array(t_word_node *head, char *cmd_name);
int			free_all(t_node *tree);
int			free_tree(t_node *head);
void		print_array_of_strings(char **arr);
char		**ft_strdup2(char **str);
void		process_signals(int status, t_data *d);
int			restore_stdout(t_data *data);
int			restore_stdin(t_data *data);
void		clean_tree(t_node *root);

#endif