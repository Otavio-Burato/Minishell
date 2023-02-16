NAME=minishell
SRCS=main.c

OBJS=$(SRCS:.c=.o)
CC=cc
CFLAGS=-Werror -Wall -Wextra -fsanitize=address
HEADER=minishell.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all