# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 09:11:13 by jsteenpu          #+#    #+#              #
#    Updated: 2024/04/04 12:49:19 by osarsari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable file / name
NAME = cub3D

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

# Source files
SRCS =	src/main.c \
		src/init_checks.c \
		src/init_game.c \
		src/init_graphics.c \
		src/key_press.c \
		src/key_movement.c \
		src/map_checks.c \
		src/map_grid.c \
		src/map_type_id.c \
		src/map_rgb.c \
		src/map_utils.c \
		src/raycasting.c \
		src/raycasting_calcul.c \
		src/raycasting_draw.c \
		src/textures.c \
		src/free.c \

# Object files
SRCS_OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCS_OBJS)
	make -C ./libs/libft
	$(CC) $(CFLAGS) $(MLX) -Llibs/libft -lft -o $@ $^

all: $(NAME)

clean:
	make clean -C ./libs/libft
	rm -f $(SRCS_OBJS)

fclean: clean
	make fclean -C ./libs/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
