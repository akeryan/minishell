# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:43:23 by dabdygal          #+#    #+#              #
#    Updated: 2024/02/17 16:36:48 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************INITIALIZE********************************* #

BIN_NAME = minishell

INCLUDE_DIR = include

MAIN_DIR = .

SRC_DIR = src

OBJ_DIR = src

LIB1_DIR = readline

LIB1_GIT = git://git.savannah.gnu.org/readline.git

LIBFT_DIR = libft

LIBFT_NAME = libft.a

LIB1_NAME = libreadline.a

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
				main_utils.h

MAIN_FILE = main.c

SRC_FILES = token_utils_0.c \
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
			run/word_list.c \
			run/path.c \
			run/rules_command.c \
			run/rules_pipeline.c \
			run/rules.c \
			run/rules_redirect.c \
			run/expansion_utils.c \
			run/tilde_expansion.c \
			run/dollar_expansion.c \
			run/free.c

OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I $(INCLUDE_DIR) -I .

# ************************************RULES*********************************** #

$(BIN_NAME): $(addprefix $(LIB1_DIR)/,$(LIB1_NAME)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(PRINTF_DIR)/,$(PRINTF_NAME)) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(OBJ_DIR)/,$(OBJ_FILES)) $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))
	$(CC) $(CFLAGS) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(PRINTF_DIR)/,$(PRINTF_NAME)) -lreadline -o $(BIN_NAME)

$(addprefix $(LIB1_DIR)/,$(LIB1_NAME)): | $(addprefix $(LIB1_DIR)/,Makefile)
	make -C $(LIB1_DIR)

$(addprefix $(LIB1_DIR)/,Makefile): | $(LIB1_DIR)
	(cd $(LIB1_DIR); ./configure)

$(LIB1_DIR):
	git clone $(LIB1_GIT)

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
	make clean -C $(LIB1_DIR)

fclean: clean
	rm -f $(BIN_NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
