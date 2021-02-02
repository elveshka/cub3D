# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 22:47:48 by esnowbal          #+#    #+#              #
#    Updated: 2020/10/28 23:44:26 by esnowbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEAD = cub3d.h
LIB = libmlx.dylib ./libft/libft.a

SRCS = i_am_parser.c i_am_map_parser.c i_am_map_reader.c i_am_structure.c \
		i_am_cub3d.c i_am_sprite_engine.c i_am_print3d.c \
		i_am_sprite_engine_utils.c i_am_screenshot.c i_am_main_function.c \
		i_am_parser_utils.c i_am_textures_init.c i_am_map_validating.c \
		i_am_cub3d_utils.c i_like_to_move_it.c i_am_epic_raycasting.c \
		i_am_wall_painter.c i_am_wall_painter_utils.c i_am_a_joke.c \
		i_am_sprite_painter.c i_am_sprite_engine_utils2.c \
		i_am_res_checker.c i_am_map_name_checker.c

SRCO = i_am_parser.o i_am_map_parser.o i_am_map_reader.o i_am_structure.o \
		i_am_cub3d.o i_am_sprite_engine.o i_am_print3d.o \
		i_am_sprite_engine_utils.o i_am_screenshot.o i_am_main_function.o \
		i_am_parser_utils.o i_am_textures_init.o i_am_map_validating.o \
		i_am_cub3d_utils.o i_like_to_move_it.o i_am_epic_raycasting.o \
		i_am_wall_painter.o i_am_wall_painter_utils.o i_am_a_joke.o \
		i_am_sprite_painter.o i_am_sprite_engine_utils2.o \
		i_am_res_checker.o i_am_map_name_checker.o

all: $(NAME)

$(SRCO): %.o:%.c $(HEAD)
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(SRCO) $(HEAD)
	cd ./libft && make && cd ..
	cd ./mlx && make && cp libmlx.dylib ../ && cd ..
	gcc $(SRCO) -o $(NAME) -L. $(LIB) -framework OpenGL -framework AppKit
	
clean:
	cd ./libft && make clean && cd ..
	cd ./mlx && make clean && cd ..
	/bin/rm -rf $(SRCO)

fclean: clean
	cd ./libft && make fclean && cd ..
	/bin/rm -rf libmlx.dylib
	/bin/rm -rf $(NAME)

norm:
	norminette *.c *.h libft/*.c libft/*.h

run: all norm
	./cub3D 1.cub

re: fclean all

bonus: all

.PHONY: clean fclean re
