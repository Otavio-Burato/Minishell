# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msander <msander@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 14:02:16 by oburato           #+#    #+#              #
#    Updated: 2023/02/22 15:34:18 by msander          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c \
		ft_isprint.c	ft_strlen.c		ft_toupper.c	ft_tolower.c \
		ft_strchr.c		ft_strrchr.c	ft_strncmp.c	ft_strnstr.c \
		ft_atoi.c		ft_strlcpy.c	ft_strlcat.c	ft_strdup.c \
		ft_bzero.c		ft_memset.c		ft_memmove.c	ft_memcpy.c \
		ft_memchr.c		ft_memcmp.c		ft_calloc.c		ft_strjoin.c \
		ft_substr.c		ft_strtrim.c	ft_split.c		ft_itoa.c \
		ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c \
		ft_putendl_fd.c	ft_putnbr_fd.c	ft_free.c

OBJS=$(SRCS:.c=.o)
CC=cc
CFLAGS= -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
