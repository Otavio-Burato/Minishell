# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 19:01:36 by oburato           #+#    #+#              #
#    Updated: 2023/03/12 13:33:53 by oburato          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
SRCS=main.c				\
	debug.c				\
	ft_readline.c		\
	ft_tokenize.c		\
	find_cmd.c			\
	ft_signal.c			\
	ft_free.c			\
	builtins/pwd.c		\
	builtins/echo.c		\
	builtins/cd.c		\
	builtins/exit.c		\

OBJS=$(SRCS:%.c=./build/%.o)
./build/%.o: %.c $(HEADER)
	mkdir -p ./build
	mkdir -p ./build/builtins
	$(CC) -c $(CFLAGS) $< -o $@

CC=cc
CFLAGS=-Werror -Wall -Wextra -fPIC -g3 #-fsanitize=address
# remove late                 ^^^^

LINKERS = -lrt -lm -lreadline
HEADER=minishell.h

LIBFT = ./libft/libft.a

all: $(NAME)
	@make all -C ./libft/

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LINKERS) -o $(NAME)

$(LIBFT):
	@make -C ./libft/

clean:
	@make clean -C ./libft/
	rm -rf $(OBJS)
	rm -rf ./build

fclean: clean
	@make fclean -C ./libft/
	rm -rf $(NAME)

re: fclean all

# Used in pipeline to run the tests
SO_LIBS=/lib/x86_64-linux-gnu/libreadline.so /lib/x86_64-linux-gnu/libhistory.so
shared: $(OBJS) $(HEADER) $(LIBFT)
	@$(CC) -shared -o ./test/load.so $(OBJS) $(SO_LIBS) $(LIBFT)

cleant: clean
	@rm -rf ./test/load.so

test: re cleant shared

run:	all
	@valgrind --track-fds=yes --quiet -s --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --trace-children-skip='/bin/,/sbin/,/usr/' --suppressions=readline.supp ./minishell

.PHONY:	all clean fclean re
