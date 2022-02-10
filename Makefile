# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 17:49:34 by lbenedar          #+#    #+#              #
#    Updated: 2021/01/06 21:36:17 by lbenedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		ft_printf.c	\
			parser/ft_new_ph.c \
			parser/ft_parse_ph.c \
			parser/ft_parser.c \
			parser/ft_precision_parser.c \
			parser/ft_star_parser.c \
			parser/ft_type_parser.c \
			parser/ft_width_parser.c \
			parser/ft_spec_parser.c\
			processor/ft_proc_char.c \
			processor/ft_processor.c \
			processor/ft_proc_str.c \
			processor/ft_proc_percent.c \
			processor/ft_proc_hex.c \
			processor/ft_proc_int.c \
			processor/ft_proc_unsign.c \
			processor/ft_proc_pointer.c \
			processor/ft_proc_oct.c \
			processor/ft_proc_output.c \
			processor/ft_proc_zero_flag.c \
			processor/ft_proc_spec_us.c \
			processor/ft_proc_spec_s.c

OBJS =		$(SRCS:.c=.o)

RM =		rm -f

CC =		gcc

AR =		ar rs

CFLAGS =	-Wall -Werror -Wextra

LIBFTDIR =	libft

LIBFTNAME =	libft.a

MAKE =		make

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)
	$(AR) $(NAME) $(OBJS)
all: $(NAME)

clean:
	$(RM) $(wildcard */*.o) $(wildcard *.o) $(wildcard $(LIBFTDIR)/$(LIBFTNAME))
fclean: clean
	$(RM) $(NAME)
re: fclean all

bonus: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re