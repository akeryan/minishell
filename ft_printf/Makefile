# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeryan <akeryan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 06:44:20 by akeryan           #+#    #+#              #
#    Updated: 2023/12/21 21:47:12 by akeryan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs

MANDATORY = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_hx.c \
			ft_putnbr_u.c ft_putptr.c ft_putstr.c 

OBJ = $(patsubst %.c, %.o, $(MANDATORY))

%.o: %.c 
	$(CC) $(FLAGS) -o $@ -c $< 


$(NAME): $(OBJ)
	$(AR) $@ $^

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
