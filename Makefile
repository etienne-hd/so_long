CC=cc
NAME = so_long
MLX_DIR = mlx/
SRC_DIR = srcs/
SRCS = $(SRC_DIR)so_long.c \
		$(SRC_DIR)parser.c \
		$(SRC_DIR)map.c \
		$(SRC_DIR)map_checker.c \
		$(SRC_DIR)map_flood_fill.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)player.c \
		$(SRC_DIR)game/texture.c \
		$(SRC_DIR)game/game.c \
		$(SRC_DIR)game/event/on_move.c \
		$(SRC_DIR)game/event/on_update.c \
		$(SRC_DIR)game/event/on_collect.c \
		$(SRC_DIR)game/event/on_exit.c \
		$(SRC_DIR)game/hook/key_hook.c \
		$(SRC_DIR)game/hook/window_hook.c

OBJ_DIR = objs/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g \
		-I includes \
		-I libft \
		-I libft/ft_printf/includes \
		-I libft/get_next_line/ \
		-I $(MLX_DIR)includes

LDFLAGS = $(LIBFT) $(MLX_DIR)libmlx.so -lSDL2

all:$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p objs/
	@mkdir -p objs/game
	@mkdir -p objs/game/event
	@mkdir -p objs/game/hook
	$(CC) $(CFLAGS) $< -c -o $@

$(LIBFT):
	$(MAKE) -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean

run: all
	./$(NAME) $(ARGS)

run2: all
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME) $(ARGS)

re: fclean all

.PHONY: all fclean clean run run2 re
