/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:18:15 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/13 22:25:00 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../include/libft.h"


//void	tilde_expansion(char *word)
//{
	//char	*homedir;
	//char	*logname;

	//char	*_word;
	//char	*tilde_expanded;
	//char	*slash;

	//logname = "akeryan";
	//homedir = "/Users/";
	//_word = word;

	//if (!word)
		//return (NULL);

	//if (_word[0] != '~')
		//return ;

 ////check whether there is an unquoted slash




	//if (slash)
	//{
		//if (is_quoted(word, slash));
			//tilde_expanded = ft_strjoin(homedir, ++word);
		//else
			//if (slash - word == 1)
				//tilde_expanded = ft_strjoin()
	//}
	//else //no slash
	//{
		//if (ft_strlen(word) > 1)
			//tilde_expanded = ft_strjoin(homedir, ++word);
		//else
			//tilde_expanded = ft_strjoin(homedir, logname);
	//}

	
	//tilde_expanded = ft_strjoin(path, ++word);
	//printf("%s\n", new_word);
//}

bool	is_quoted(const char *str, const char *target)
{
	const char	*current;
	bool		quoted;
	bool		escape_sequence;

	quoted = false;
	escape_sequence = false;
	current = str;
	while (current != target)
	{
		if (*current == '\\' && !escape_sequence)
		{
			escape_sequence = true;
			current++;
			continue ;
		}
		if ((*current == '"' || *current == '\'') && !escape_sequence)
			quoted = !quoted;
		else
			escape_sequence = false;
		current++;
	}
	if ((*current == '"' || *current == '\'') && !escape_sequence)
		quoted = !quoted;
	return (quoted);
}

char	*is_there_unquoted_slash(char *word)
{
	char	*_word;
	char	*slash;

	_word = word;
	slash = NULL;
	while (1)
	{
		slash = ft_strchr(_word, '/');
		if (!slash)
			break ;	
		if (!is_quoted(word, slash))
			break ;
		if (*(slash + 1) != '\0')
			_word = (slash + 1);
		else
			break ;
	}
	return (slash);
}

int main(void) {
	//char str[] = "Hello, \"world\", how's 'your' day?";

	//bool result;

	//result = is_quoted(str, &str[28]);
	//if (result == true)
		//printf("YES\n");
	//else
		//printf("NO\n");
	char str[] = "~sdffs'sdf/";
	char *slash;
	slash = is_there_unquoted_slash(str);
	if (slash)
		printf("Yes: (%ld) %c\n", slash - str, *slash);
	else
		printf("NO\n");
	return 0;	
}