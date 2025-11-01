CC=cc
NAME = so_long
SRC_DIR = srcs/
SRCS = $(SRC_DIR)so_long.c \
		$(SRC_DIR)parser.c \
		$(SRC_DIR)map.c \
		$(SRC_DIR)map_checker.c \
		$(SRC_DIR)map_flood_fill.c \
		$(SRC_DIR)utils.c
		

OBJ_DIR = objs/
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
LIBFT = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror -g -I includes -I libft -I libft/ft_printf/includes -I MacroLibX/includes -I libft/get_next_line/
LDFLAGS = $(LIBFT)

all:$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
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
