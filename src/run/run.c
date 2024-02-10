/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:31:45 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/10 16:50:32 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "main_utils.h"
#include "ft_printf.h"
#include "rules.h"

//int	run_cmd(t_node *root)
//{
	//t_data	*data;

	//data = new_data();
	//if (data == NULL)
	//{
		//ft_printf(2, "t_data init failed\n");
		//return (-1);
	//}
	//if (create_pipes(root, data) == -1)
	//{
		//ft_printf(2, "Creation of pipes failed\n");
		//free_all(root, data);
	//}
	//if (program(root, data) == -1)
	//{
		//ft_printf(2, "Execution error\n");
		//free_all(root, data);
	//}
	//else
		//printf("%s\n", "--------EXECUTION----------");
	//return (0);
//}

void run_cmd(t_node *node)
{
	if (!node)
		exit(EXIT_FAILURE);
	if (node->node_type == PROGRAM)
		program(node);
	else if (node->node_type == PIPELINE)
		pipeline(node);
	else if (node->node_type == COMMAND)
		command(node);
	//else if (node->node_type == PREFIX)
		//prefix(node);
	//else if (node->node_type == SUFFIX)
		//suffix(node);
	else if (node->node_type == IO_REDIR)
		redirect(node);
	else if (node->node_type == NEWLINE_LIST)
		newline_list(node);		
	return ;
}