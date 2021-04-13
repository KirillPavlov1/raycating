# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 17:21:49 by cvirgin           #+#    #+#              #
#    Updated: 2021/04/13 22:39:46 by cvirgin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = main.c  parser/new_parser.c get_next_line/get_next_line.c\
	 get_next_line/get_next_line_utils.c map/make_map.c utils/free.c\
	 utils/create_mlx.c utils/ft_newmlx.c utils/find_player.c\
	 map/draw_map.c map/run_game.c utils/sides.c map/draw_3d.c\
	 utils/init_net2.c utils/get_color.c utils/sprites.c map/draw_sprite.c\
	 utils/check_ext.c utils/make_screen.c map/validator.c parser/parser_help.c\
	 utils/check_line.c utils/ft_error.c utils/only_space.c utils/main_dop.c\
	 utils/cross_sprite.c map/second3d.c map/third3d.c map/move_player.c parser/parser_help2.c\
	 utils/pour.c utils/init_net3.c utils/sprites2.c

OBJ = main.o  parser/new_parser.o get_next_line/get_next_line.o\
	 get_next_line/get_next_line_utils.o map/make_map.o utils/free.o\
	 utils/create_mlx.o utils/ft_newmlx.o utils/find_player.o\
	 map/draw_map.o map/run_game.o utils/sides.o map/draw_3d.o\
	 utils/init_net2.o utils/get_color.o utils/sprites.o map/draw_sprite.o\
	 utils/check_ext.o utils/make_screen.o map/validator.o parser/parser_help.o\
	 utils/check_line.o utils/ft_error.o utils/only_space.o utils/main_dop.o\
	 utils/cross_sprite.o map/second3d.o map/third3d.o map/move_player.o parser/parser_help2.o\
	 utils/pour.o utils/init_net3.o utils/sprites2.o

INCLUDE = cub.h

FLAGS = -Wall -Wextra -Werror

OS			:= $(shell uname)

ifeq ($(OS), Darwin)
LIB_FLAGS	= -Llibmlx -lmlx -framework OpenGL -framework AppKit
LIB_DIR		= libmlx
else
LIB_FLAGS	= -Llibmlx -lmlx -framework OpenGL -framework AppKit
LIB_DIR		= libmlx
endif

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	make bonus -C libft
	make -C $(LIB_DIR)
	gcc $(FLAGS) $(SRC) -g -Llibft -lft $(LIB_FLAGS) -o $(NAME) 

%.o: %.c 
	gcc -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean:	clean
	make fclean -C libft
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re