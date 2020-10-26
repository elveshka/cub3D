# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/05 15:03:40 by esnowbal          #+#    #+#              #
#    Updated: 2020/10/26 18:43:02 by esnowbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNC = i_am_parser.c i_am_map_parser.c i_am_map_reader.c i_am_structure.c \
		i_am_cub3d.c create_trgb.c i_am_sprite_engine.c \
		i_am_sprite_engine_utils.c i_am_screenshot.c

COMPILE = gcc
FLAGS = -lmlx -framework OpenGL -framework AppKit

HEADER = cub3d.h

OBJ = $(FUNC:%.c=%.o)

all: $(HEADER)
	$(COMPILE) $(FUNC) $(FLAGS) libft/libft.a

# $(NAME)
# $(NAME): libft/libft.a $(OBJ) $(HEADER)
# 	ar rcs $(NAME) $(OBJ)
# libft/libft.a:
# 	make -C libft
# 	cp libft/libft.a $(NAME)
# clean:
# 	make fclean -C libft/
# 	rm -f $(OBJ)
# fclean: clean
# 	rm -f $(NAME)
re: all
.PHONY: clean fclean re all