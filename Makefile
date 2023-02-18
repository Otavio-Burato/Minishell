# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 19:01:36 by oburato           #+#    #+#              #
#    Updated: 2023/02/18 18:51:26 by oburato          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
SRCS=main.c			\
	ft_readline.c	\
	ft_tokenize.c

OBJS=$(SRCS:%.c=./build/%.o)
./build/%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

CC=cc
CFLAGS=-Werror -Wall -Wextra -fPIC ##-fsanitize=address
# remove late                 ^^^^
LINKERS = -lrt -lm -lreadline
HEADER=minishell.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINKERS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# Used in pipeline to run the tests
SO_LIBS=/lib/x86_64-linux-gnu/libreadline.so /lib/x86_64-linux-gnu/libhistory.so
shared: $(OBJS) $(HEADER)
	@$(CC) -shared -o ./test/load.so $(OBJS) $(SO_LIBS)

cleant: clean
	@rm -rf ./test/load.so

test: cleant shared

run:	all
	@valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --trace-children-skip='/bin/,/sbin/' --suppressions=readline.supp ./minishell
