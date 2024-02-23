/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:00:39 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/23 19:32:49 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "grammar.h"

# define MSH_SYNTAX 200

t_node	*parse(t_node_type node_type, t_grammar *grammar, char *ps2);
char	*here_file(t_token token);
void	erase_node(t_node **node);
char	*here_file(t_token token);
int		fill_node(t_node *node, t_book *book, t_grammar *grammar, char *ps2);
int		parse_ing(t_ingredient *ing, t_node *node, t_grammar *gr, char *ps2);
t_node	*build_tree(t_grammar *grammar, char *ps2);

#endif
