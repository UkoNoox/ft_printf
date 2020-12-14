# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 17:06:55 by ugdaniel          #+#    #+#              #
#    Updated: 2020/12/14 15:26:29 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
HEADERS	=	./includes/ft_printf.h

LIBPATH	=	./libft/
LIBNAME	=	libft.a

SRCS	=	./srcs/ft_printf.c \
			./srcs/ft_flags.c \
			./srcs/ft_flags_plus.c \
			./srcs/ft_utils.c \
			./srcs/ft_out.c \
			./srcs/ft_out_plus.c

OBJS	= $(SRCS:c=o)

CC		= @clang
FLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJS)
	@make -C $(LIBPATH) 1> /dev/null
	@echo "$(LIBNAME) created"
	@cp $(LIBPATH)$(LIBNAME) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created"

%.o: %.c
	$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@

libft:
	@make -C $(LIBPATH) 1> /dev/null

all: $(NAME)

clean:
	@make clean -C $(LIBPATH) 1> /dev/null
	@rm -f $(OBJS)
	@echo ".o files deleted"

fclean: clean
	@make fclean -C $(LIBPATH) 1> /dev/null
	@echo "$(LIBNAME) deleted"
	@if (rm $(NAME) 2> /dev/null); then echo "$(NAME) deleted"; else echo "Nothing to be done for libftprintf.a"; fi;

re: fclean all
