NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit
SRC_DIR = src
UTILS_DIR = src/utils
SRC = \
	$(UTILS_DIR)/utils.c \
	$(UTILS_DIR)/frexit.c \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/ray_cast.c \
	$(SRC_DIR)/movement.c \
	$(UTILS_DIR)/draw_line.c \

OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX)

clean:
	$(RM) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all clean
	./$(NAME)

.PHONY: all clean fclean re run