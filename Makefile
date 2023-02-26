# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 19:01:36 by oburato           #+#    #+#              #
#    Updated: 2023/02/26 20:04:01 by oburato          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
SRCS=main.c				\
	ft_readline.c		\
	ft_tokenize.c		\
	find_cmd.c			\
	builtins/pwd.c		\
	builtins/echo.c		\

OBJS=$(SRCS:%.c=./build/%.o)
./build/%.o: %.c $(HEADER)
	mkdir -p ./build
	mkdir -p ./build/builtins
	$(CC) -c $(CFLAGS) $< -o $@

CC=cc
CFLAGS=-Werror -Wall -Wextra -fPIC #-fsanitize=address
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
	@valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --trace-children-skip='/bin/,/sbin/' --suppressions=readline.supp ./minishell

.PHONY:	all clean fclean re
