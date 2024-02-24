# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:43:23 by dabdygal          #+#    #+#              #
#    Updated: 2024/02/24 12:44:53 by dabdygal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************INITIALIZE********************************* #

BIN_NAME = minishell

INCLUDE_DIR = include

MAIN_DIR = .

SRC_DIR = src

OBJ_DIR = src

LIBREAD_DIR = /usr/local/Cellar/readline/8.1/lib

LIBREAD_INC = /usr/local/Cellar/readline/8.1/include

LIBFT_DIR = libft

LIBFT_NAME = libft.a

PRINTF_DIR = ft_printf

PRINTF_NAME = libftprintf.a

INCLUDE_FILES = minishell.h \
				tokens.h \
				grammar.h \
				libft.h \
				data.h \
				parse.h \
				data.h \
				error_handling.h \
				ft_printf.h \
				pid_list.h \
				pipe_list.h \
				rules.h \
				word_list.h \
				free.h \
				expansion.h \
				dollar_expansion.h \
				main_utils.h

MAIN_FILE = main.c

SRC_FILES = signals.c \
			echo.c \
			cd.c \
			export_0.c \
			export_1.c \
			pwd.c \
			unset.c \
			env.c \
			ft_exit.c \
			token_utils_0.c \
			token_utils_1.c \
			setup_grammar.c \
			setup_grammar_utils.c \
			erase_node.c \
			here_file.c \
			parse_0.c \
			parse_1.c \
			main_utils.c \
			run/error_handling.c \
			run/pid_list.c \
			run/pipe_list.c \
			run/word_list_0.c \
			run/word_list_1.c \
			run/path.c \
			run/rules_command.c \
			run/rules_pipeline.c \
			run/rules.c \
			run/rules_redirect.c \
			run/expansion_utils_0.c \
			run/expansion_utils_1.c \
			run/tilde_expansion.c \
			run/dollar_expansion_0.c \
			run/dollar_expansion_1.c \
			run/dollar_expansion_2.c \
			run/free.c

OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I $(INCLUDE_DIR) -I $(LIBREAD_INC)

# ************************************RULES*********************************** #

$(BIN_NAME): $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(PRINTF_DIR)/,$(PRINTF_NAME)) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(OBJ_DIR)/,$(OBJ_FILES)) $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))
	$(CC) $(CFLAGS) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(PRINTF_DIR)/,$(PRINTF_NAME)) -L$(LIBREAD_DIR) -lreadline -o $(BIN_NAME)

$(addprefix $(OBJ_DIR)/,$(OBJ_FILES)): $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))

$(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)):
	make $(LIBFT_NAME) -C $(LIBFT_DIR)

$(addprefix $(PRINTF_DIR)/,$(PRINTF_NAME)):
	make $(PRINTF_NAME) -C $(PRINTF_DIR)

all: $(BIN_NAME)

clean:
	rm -f $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(BIN_NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
