/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:21:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/04 13:59:34 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
//#include "libft.h"
#include "minishell.h"
#include "execute.h"
#include "readline/history.h"
#include "data.h"

static char	*token_type(t_token_type type)
{
	if (type == EOF_TOKEN)
		return ("EOF");
	else if (type == NEWLINE_TOKEN)
		return ("NEWLINE");
	else if (type == PIPE)
		return ("PIPE");
	else if (type == DLESS)
		return ("DLESS");
	else if (type == DGREAT)
		return ("DGREAT");
	else if (type == LESS)
		return ("LESS");
	else if (type == GREAT)
		return ("GREAT");
	else if (type == WORD)
		return ("WORD");
	return ("ERROR!!!");
}

int	main(void)
{
	t_token	token;
	t_data	data;
	t_node	parser_tree;

	{
		init_data(&data);
		parse(&parser_tree);
		if(create_pipes(&parser_tree, &data) != 0)
		{
			clean_memory(&parser_tree, &data);
			//exit
		}
	}

	while (1)
	{
		token = consume_token();
		printf("%s(%zu) ", token_type(token.type), token.slice.length);
		if (token.type == NEWLINE_TOKEN)
			printf("\n");
		if (token.type == EOF_TOKEN)
		{
			printf(EXIT_MSG);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}

void clean_memory(t_node *tree, t_data *data)
{
	free_tree(tree);
	free_data(data);
}
