CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
HEADER = includes/ft_printf.h
SRCDIR=srcs
INCLUDE=-Iincludes

SRCS = $(SRCDIR)/ft_printf.c $(SRCDIR)/ft_putaddr.c $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_putnbr.c $(SRCDIR)/ft_putnbrhexa.c \
	$(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_putunbr.c $(SRCDIR)/ft_startwith.c $(SRCDIR)/ft_strcmp.c $(SRCDIR)/ft_strlen.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
