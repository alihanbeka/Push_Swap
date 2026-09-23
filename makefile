NAME = Push_Swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
	parse.c \
	ft_Atoi.c \
	check_duplicate.c \
	create_stack.c \
	stack_clear.c \
	index_assignment.c \
	disorder.c \
	swap.c \
	push.c \
	rotate.c \
	reverse.c \
	sort_simple.c \
	sort_medium.c \
	sort_complex.c \
	sort_strategy.c \
	bench.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c Push_Swap.h $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean
	$(MAKE) all

FORCE:

.PHONY: all clean fclean re FORCE