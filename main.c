/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:21:52 by akeryan           #+#    #+#             */
/*   Updated: 2024/01/11 19:02:40 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "readline.h"
#include "history.h"

int main() {
    char *input;

    while ((input = readline("Enter command: ")) != NULL) {
        if (*input) {  // Only add non-empty strings to the history
            add_history(input);
        }

        printf("You entered: %s\n", input);
        free(input);
    }

    return 0;
}
