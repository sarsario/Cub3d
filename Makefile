NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -L./mlx -lmlx -framework OpenGL -framework AppKit
SRC_DIR = src
UTILS = $(SRC_DIR)/utils
SRC = \
	$(SRC_DIR)/main.c \
	$(UTILS)/utils.c \
	$(UTILS)/draw_bg.c \

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

run: all
	./$(NAME)

.PHONY: all clean fclean re run