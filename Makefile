# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 14:38:17 by ofranco           #+#    #+#              #
#    Updated: 2017/10/16 19:52:19 by ofranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d 

SRCPATH = ./srcs/

HEADER = ./includes/

SRCS = ray_x.c color.c hook.c image.c window.c raytracer2.c ray_y.c parsing.c main.c

LIB = Libft/Libft.a

OBJ = $(SRCS:.c=.o)

FLAGS += -Wall -Wextra -Werror

FSRCS = $(addprefix $(SRCPATH), $(SRCS))

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(FSRCS)
	make -C libft/
	gcc $(FLAGS) -I $(HEADER) minilibx_macos/libmlx.a -g -framework OpenGL -framework AppKit $(LIB) $(FSRCS) -o $(NAME) 

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
