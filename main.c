/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:21:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/04 22:40:44 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "minishell.h"
#include <stdlib.h>
#include "parse.h"
#include <sys/errno.h>

// static char	*token_type(t_token_type type)
// {
// 	if (type == EOF_TOKEN)
// 		return ("EOF");
// 	else if (type == NEWLINE_TOKEN)
// 		return ("NEWLINE");
// 	else if (type == PIPE)
// 		return ("PIPE");
// 	else if (type == DLESS)
// 		return ("DLESS");
// 	else if (type == DGREAT)
// 		return ("DGREAT");
// 	else if (type == LESS)
// 		return ("LESS");
// 	else if (type == GREAT)
// 		return ("GREAT");
// 	else if (type == WORD)
// 		return ("WORD");
// 	return ("ERROR!!!");
// }

int	main(void)
{
	t_grammar	grammar;
	t_node		*root;

	grammar = setup_grammar();
	root = parse(PROGRAM, &grammar);
	while (root)
	{
		printf("Root: %i\n", root->node_type);
		root = parse(PROGRAM, &grammar);
	}
	return (EXIT_SUCCESS);
}
