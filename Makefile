# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 11:46:05 by akeryan           #+#    #+#              #
#    Updated: 2023/12/27 13:36:53 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

BLINKS = -I$(INCLUDE) -I$(READLINE_DIR)/include/readline -I$(READLINE_DIR)/include -L$(READLINE_DIR)/lib -lreadline -lhistory
OLINKS = -I$(INCLUDE) -I$(READLINE_DIR)/include/readline -I$(READLINE_DIR)/include 

CURRENT_DIR = $(shell pwd)
INCLUDE = include
SRC_DIR = src
READLINE_DIR = readline
BUILD_DIR = build

MANDATORY = main.c

all: $(NAME)

OBJ = $(patsubst %.c, %.o, $(MANDATORY))

$(NAME): submodules_init_update readline_add $(OBJ) 
	$(CC) $(FLAGS) $(BLINKS) -o $@ $(OBJ) 
	
%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) $(OLINKS) -c $< -o $@ 

readline_add:
	cd $(READLINE_DIR) && ./configure --prefix=$(CURRENT_DIR)/$(READLINE_DIR)
	make -C $(READLINE_DIR)
	make -C $(READLINE_DIR) install

submodules_init_update:
	git submodule update --init

print_obj:
	@echo "==============================================================================="

clean_readline:
	@if [ -f $(READLINE_DIR)/Makefile ]; then \
		make -C $(READLINE_DIR) clean; \
	fi

fclean_readline:
	@if [ -f $(READLINE_DIR)/Makefile ]; then \
		make -C $(READLINE_DIR) uninstall; \
		make -C $(READLINE_DIR) distclean; \
	fi
	rm -rf $(READLINE_DIR)/bin
	rm -rf $(READLINE_DIR)/include
	rm -rf $(READLINE_DIR)/lib
	rm -rf $(READLINE_DIR)/share

clean: clean_readline
	$(RM) $(OBJ)

fclean: clean fclean_readline
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
