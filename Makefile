# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rporcon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 15:14:43 by rporcon           #+#    #+#              #
#    Updated: 2015/12/11 17:57:33 by rporcon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = @gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT = -L. -lft

SRC = check_all_tetriminos.c check_tetriminos_1.c check_tetriminos_2.c \
	  functions.c get_tetrigrid.c get_tetriline.c main.c more_functions.c \
	  move_tetri.c norme_terror.c norme_tgrid.c resolve.c resolve_part1.c \
	  resolve_part2.c tetri_error.c try_soluce4.c

OBJ = $(SRC:.c=.o)

all: tetriminos.h $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
