/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/28 20:20:13 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "execute.h"

void command(t_node *node, t_data *d)
{
	char **argv;

	//fork()
	execute(node->left, d); //prefix
	argv = execute(node->right, d); //suffix
	//execve(WORD)	
}