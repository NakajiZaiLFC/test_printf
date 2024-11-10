NAME = tester
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
FT_PRINTF_PATH = ../ # ft_printf.aがある親ディレクトリへのパス

SRCS = test_printf.c
OBJS = $(SRCS:.c=.o)

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full \
				 --show-leak-kinds=all \
				 --track-origins=yes \
				 --verbose \
				 --log-file=valgrind-out.txt \
				 -s

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(FT_PRINTF_PATH) -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(FT_PRINTF_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f valgrind-out.txt

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "\033[34m=== Running tests with Valgrind ===\033[0m"
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME)
	@echo "\033[34m=== Valgrind Summary ===\033[0m"
	@grep "ERROR SUMMARY:" valgrind-out.txt || true
	@grep "LEAK SUMMARY:" valgrind-out.txt || true
	@grep "HEAP SUMMARY:" valgrind-out.txt || true

.PHONY: all clean fclean re test
