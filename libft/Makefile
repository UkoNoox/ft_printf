# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 12:23:21 by ugdaniel          #+#    #+#              #
#    Updated: 2020/12/14 15:20:17 by ugdaniel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
HEADERS	=	libft.h
SRCS	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putrstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_base_fd.c \
			ft_putnbr_fd.c \
			ft_lstadd_front.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

CC		=	@clang
FLAGS	=	-Wall -Wextra -Werror
OBJS	=	$(SRCS:c=o)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created"

%.o: %.c
	$(CC) $(FLAGS) -I $(HEADERS) -o $@ -c $< 

all: $(NAME)

bonus: $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@echo ".o files deleted"

fclean: clean
	@if (rm $(NAME) 2> /dev/null); then echo "$(NAME) deleted"; else echo "Nothing to be done for libft.a"; fi;

re: fclean all

.PHONY: all bonus clean fclean re
