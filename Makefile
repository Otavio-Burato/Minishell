# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msander <msander@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 19:01:36 by oburato           #+#    #+#              #
#    Updated: 2023/02/22 16:14:27 by msander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
SRCS=main.c			\
	ft_readline.c	\
	ft_tokenize.c	\
	find_cmd.c		\
	pwd.c 	
	# builtins/pwd.c 	

OBJS=$(SRCS:%.c=./build/%.o)
./build/%.o: %.c $(HEADER)
	mkdir -p ./build
	$(CC) -c $(CFLAGS) $< -o $@

CC=cc
CFLAGS=-Werror -Wall -Wextra -fPIC ##-fsanitize=address
# remove late                 ^^^^

LINKERS = -lrt -lm -lreadline
HEADER=minishell.h

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LINKERS) -o $(NAME)

$(LIBFT):
	@make -C ./libft/

clean:
	@make clean -C ./libft/
	rm -rf $(OBJS)

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

test: cleant shared

run:	all
	@valgrind -q --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --trace-children-skip='/bin/,/sbin/' --suppressions=readline.supp ./minishell

.PHONY:	all clean fclean re
