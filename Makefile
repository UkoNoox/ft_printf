# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 17:06:55 by ugdaniel          #+#    #+#              #
#    Updated: 2020/12/08 20:11:01 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
HEADERS	=	./includes/ft_printf.h

LIBPATH	=	./libft/
LIBNAME	=	$(LIBPATH)libft.a

SRCS	=	./srcs/ft_printf.c \
			./srcs/ft_flags.c \
			./srcs/ft_flags_plus.c \
			./srcs/ft_utils.c \
			./srcs/ft_out.c \
			./srcs/ft_out_plus.c

OBJS	= $(SRCS:c=o)

CC		= clang
FLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJS)
	make -C $(LIBPATH)
	cp $(LIBNAME) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@

libft:
	make -C $(LIBPATH)

all: $(NAME)

clean:
	make clean -C $(LIBPATH)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBPATH)
	rm -f $(NAME)

re: fclean all
