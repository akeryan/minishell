/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:03:48 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/28 12:06:32 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_pipe_node
{
	int					fd[2];
	struct s_pipe_node	*next;
}	t_pipe_node;

	