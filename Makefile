# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 15:43:23 by dabdygal          #+#    #+#              #
#    Updated: 2024/01/11 18:45:32 by dabdygal         ###   ########.fr        #
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

LIB1_NAME = readline.a

INCLUDE_FILES = minishell.h \
				readline/readline.h

MAIN_FILE = main.c

SRC_FILES = 

OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_DIR)

# ************************************RULES*********************************** #

$(BIN_NAME):  $(addprefix $(LIB1_DIR)/,$(LIB1_NAME)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(OBJ_DIR)/,$(OBJ_FILES)) $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))
	$(CC) $(CFLAGS) $(addprefix $(MAIN_DIR)/,$(MAIN_FILE)) $(addprefix $(SRC_DIR)/,$(SRC_FILES)) $(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)) $(addprefix $(LIB1_DIR)/,$(LIB1_NAME)) -o $(BIN_NAME)

$(addprefix $(LIB1_DIR)/,$(LIB1_NAME)): $(addprefix $(LIB1_DIR)/,Makefile)
	make -C $(LIB1_DIR)

$(addprefix $(LIB1_DIR)/,Makefile): $(LIB1_DIR)
	(cd $(LIB1_DIR); ./configure)

$(LIB1_DIR):
	git clone $(LIB1_GIT)

$(addprefix $(OBJ_DIR)/,$(OBJ_FILES)): $(addprefix $(INCLUDE_DIR)/,$(INCLUDE_FILES))

$(addprefix $(LIBFT_DIR)/,$(LIBFT_NAME)):
	make $(LIBFT_NAME) -C $(LIBFT_DIR)

all: $(BIN_NAME)

clean:
	rm -f $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(BIN_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
