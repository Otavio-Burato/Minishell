# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 19:01:36 by oburato           #+#    #+#              #
#    Updated: 2023/02/17 19:19:37 by oburato          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
SRCS=main.c

OBJS=$(SRCS:.c=.o)
CC=cc
CFLAGS=-Werror -Wall -Wextra -fsanitize=address
HEADER=minishell.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) ./build/$(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o ./build/$@

clean:
	rm -rf ./build/$(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

# Used in pipeline to run the tests
SOBJS=$(SRCS:.c=.so)
%.so: %.c $(HEADER)
	$(CC) -shared -o ./test/$@ $<

clean_test:
	rm -rf ./test/$(SOBJS)

test: clean_test $(SOBJS)