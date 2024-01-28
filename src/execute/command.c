/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:50:20 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/28 10:56:23 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include "execute.h"

char **command(t_node *node, t_data *d)
{
	char **argv;

	//fork()
	execute(node->left, d); //prefix
	argv = execute(node->right, d); //suffix
	//execve(WORD)	
}