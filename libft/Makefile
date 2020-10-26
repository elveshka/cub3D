# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esnowbal <esnowbal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/02 11:36:15 by esnowbal          #+#    #+#              #
#    Updated: 2020/09/06 19:16:15 by esnowbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strchr.c\
		ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_strlcpy.c\
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strlcat.c\
		ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
		ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c get_next_line.c ft_strcmp.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstmap.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

COMPILE = gcc -Wall -Wextra -Werror

HEADER = libft.h

OBJ = $(FUNC:.c=.o)

NAME = libft.a

all: $(NAME)
$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

$(OBJ): %.o: %.c $(HEADER)
	@$(COMPILE) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus
