NAME = tester
CC = cc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF_PATH = ../
SRCS = test_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(FT_PRINTF_PATH) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(FT_PRINTF_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	valgrind -q ./$(NAME)

.PHONY: all clean fclean re test
