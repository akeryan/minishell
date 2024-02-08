/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:31:45 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/08 18:56:03 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "data.h"
#include "main_utils.h"
#include "ft_printf.h"
#include "execute.h"
#include "rules.h"

int	run_cmd(t_node *root)
{
	t_data	*data;

	data = new_data();
	if (data == NULL)
	{
		ft_printf(2, "t_data init failed\n");
		return (-1);
	}
	if (create_pipes(root, data) == -1)
	{
		ft_printf(2, "Creation of pipes failed\n");
		free_all(root, data);
	}
	if (program(root, data) == -1)
	{
		ft_printf(2, "Execution error\n");
		free_all(root, data);
	}
	else
		printf("%s\n", "--------EXECUTION----------");
	return (0);
}
