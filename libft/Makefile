# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenedar <lbenedar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 15:46:31 by lbenedar          #+#    #+#              #
#    Updated: 2020/11/17 13:28:37 by lbenedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = $(filter-out $(BONUS_SRCS), $(wildcard *.c))

BONUS_SRCS = $(wildcard ft_lst*.c)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

RM = rm -f

CC = gcc

AR = ar rs

CFLAGS = -Werror -Wextra -Wall

$(NAME): $(OBJS)
	$(AR)c $(NAME) $(OBJS)
all: $(NAME)

clean:
	$(RM) $(wildcard *.o)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.c.o:
	$(CC) $(CFLAGS) -c $<
bonus: $(NAME) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
