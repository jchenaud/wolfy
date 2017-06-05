# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/31 01:31:32 by jchenaud          #+#    #+#              #
#    Updated: 2017/05/31 03:33:19 by jchenaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = src/
SRC_NAME = $(SRC_PATH)algo.c\
		   $(SRC_PATH)hook.c\
		   $(SRC_PATH)main.c\
		   $(SRC_PATH)graph.c\
		   $(SRC_PATH)parsing.c\
		   $(SRC_PATH)move.c\
		   $(SRC_PATH)draw_wall_texture.c\
		   $(SRC_PATH)weapon.c\
		   $(SRC_PATH)texture_init.c\
		   $(SRC_PATH)map_generator.c\
		   $(SRC_PATH)usage.c\




LIBFT_PATH = libft/
LIBFT_LIB = libft/libft.a

MINI_PATH = minilibx_siera/
MINI_LIB = minilibx_siera/libmlx.a

CC = gcc
FLAG = -Wall -Wextra -Werror -framework OpenGL -framework AppKit

all: $(NAME)
$(NAME):
		cd $(LIBFT_PATH) && make re
		cd $(MINI_PATH) && make re
		$(CC) $(FLAG) $(SRC_NAME) $(LIBFT_LIB) $(MINI_LIB)  -o $(NAME)
clean:
	cd $(LIBFT_PATH) && make clean	
	cd $(MINI_PATH) && make clean

fclean:
	cd $(LIBFT_PATH) && make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
