/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:18:15 by akeryan           #+#    #+#             */
/*   Updated: 2024/02/17 17:03:35 by akeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "libft.h"

/**
 * @brief Checks whether the character is quoted
 * @details Single quotation marks and double quotation marks are quotes
 * Doesn't check for unclosed quotes. In the following cases '@' is quoted:
 *  - word'word@
 *  - word"word@ 
 *  - word'sd"sdf@
 * @param str Input string that contains the character of interest
 * @param target Pointer to the character of interest
 * @return 'true' if quoted, 'false' otherwise
*/
bool	is_quoted(const char *str, const char *target)
{
	const char	*current;
	bool		dbl_quoted;
	bool		sgl_quoted;

	current = str;
	dbl_quoted = false;
	sgl_quoted = false;
	while (current <= target)
	{
		if (*current == '"')
			dbl_quoted = !dbl_quoted;
		if (*current == '\'')
			sgl_quoted = !sgl_quoted;
		current++;
	}
	return (dbl_quoted || sgl_quoted);
}

bool	is_single_quoted(const char *str, const char *target)
{
	const char	*current;
	bool		sgl_quoted;

	current = str;
	sgl_quoted = false;
	while (current <= target)
	{
		if (*current == '\'')
			sgl_quoted = !sgl_quoted;
		current++;
	}
	return (sgl_quoted);
}

/**
 * @brief Checks whether there is an unquoted slach in the input string
 * @param word input string
 * @return Pointer to the unquoted slash or NULL
 * 
*/
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
		{
			slash = NULL;
			break ;
		}
	}
	return (slash);
}

/**
 * @brief Obtains the current value of the environment variable, name
 * @param name The name of the environment variable
 * @param env Pointer to the environmet variables
 * @return Value of the env. variable if exists, otherwise NULL
*/
char	*ft_getenv(char *name, char **env)
{
	if (!name || !env)
	{
		ft_printf(2, "Empty args in ft_getenv\n");
		return (NULL);
	}
	while (*env)
	{
		if (ft_strncmp(name, *env, ft_strlen(name)) == 0)
			return (*env + ft_strlen(name) + 1);
		env++;
	}
	return (NULL);
}

/**
 * @brief Checks whether directory exists
 * @param path Path to the directory in question
 * @return non-zero if directory exists
 * @return 0 if directory doesn't exist
*/
int does_dir_exist(const char *path)
{
	struct stat status;
    if (stat(path, &status) != 0) {
        return 0;
    }
    return S_ISDIR(status.st_mode);
}
