# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcottet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 16:03:46 by fcottet           #+#    #+#              #
#    Updated: 2018/11/05 14:43:16 by fcottet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a
LIB_PATH = libft
SRC = ./src/fractol.c \
	  ./src/mandelbrot.c \
	  ./src/keyboard.c \
	  ./src/mouse.c \
	  ./src/tools.c \
	  ./src/julia.c \
	  ./src/burningship.c
OBJ = fractol.o mandelbrot.o keyboard.o mouse.o tools.o julia.o burningship.o
INC = /usr/local/include/
MNL = /usr/local/lib/
FRAME = -framework OpenGL -framework AppKit

HEAD = ./src/fractol.h
GCH = $(HEAD:.h=.h.gch)

all: $(NAME)

$(NAME): ./includes/fractol.h
	make -C $(LIB_PATH)
	$(CC) $(FLAGS) -I $(INC) $(SRC) -L $(MNL) $(LIB) -lmlx $(FRAME) -o fractol

clean:
	rm -f $(OBJ) $(GCH)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all

.PHONY : all, clean, fclean, re
