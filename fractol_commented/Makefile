NAME = fractol

SRC_DIR = src
INC_DIR = inc
LIBFT_DIR = libft
MINILIBX_DIR = minilibx

SRCS = $(SRC_DIR)/draw_fractal.c \
       $(SRC_DIR)/events.c \
       $(SRC_DIR)/init.c \
       $(SRC_DIR)/julia.c \
       $(SRC_DIR)/main.c \
       $(SRC_DIR)/mandelbrot.c \
       $(SRC_DIR)/utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

LIBFT = $(LIBFT_DIR)/libft.a

MLX = -Lminilibx -lmlx -lXext -lX11 -lm

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

#bonus:
#	make bonus -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus
