/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:00:39 by dabdygal          #+#    #+#             */
/*   Updated: 2024/02/06 04:46:32 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "grammar.h"

t_node	*parse(t_node_type node_type, t_grammar *grammar);
char	*here_file(t_token token);
void	erase_node(t_node **node);
char	*here_file(t_token token);

#endif
