NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRC_DIR = srcs
SRC = $(SRC_DIR)/main.c

RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(MLX) -o $(NAME)

clean:
	$(RM) $(SRC_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re