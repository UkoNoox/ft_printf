# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 17:06:55 by ugdaniel          #+#    #+#              #
#    Updated: 2020/12/14 16:25:13 by ugdaniel         ###   ########.fr        #
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
	@make -s -C $(LIBPATH)
	@cp $(LIBPATH)$(LIBNAME) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created"

%.o: %.c
	$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@

lib:
	@make -s re -C $(LIBPATH)

all: $(NAME)

clean:
	@make -s clean -C $(LIBPATH)
	@rm -f $(OBJS)
	@echo "$(NAME:.a=): .o files deleted"

fclean: clean
	@if (rm $(LIBPATH)$(LIBNAME) 2> /dev/null); then echo "$(LIBNAME) deleted"; else echo "Nothing to be done for $(LIBNAME)"; fi;
	@if (rm $(NAME) 2> /dev/null); then echo "$(NAME) deleted"; else echo "Nothing to be done for $(NAME)"; fi;

re: fclean all

.PHONY: all clean fclean re lib