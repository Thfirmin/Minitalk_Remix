# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                          :+:     :+:             #
#                                                     +:+ +:+         +:+      #
#    By: thino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 03:44:47 by thino             #+#    #+#              #
#    Updated: 2022/08/22 18:33:28 by Thinotsuki   ###     ###.br               #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		  ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		  ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		  ft_toupper.c

SRCS_B	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
		   ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c


OBJS	=  $(SRCS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./libft.h

$(NAME):	$(OBJS)
			make -C ./printf
			cp ./printf/libftprintf.a ./$(NAME)
			ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS_B)
			ar rcs $(NAME) $(OBJS_B)

all:		$(NAME)

clean:
			make clean -C ./printf
			rm -f $(OBJS) $(OBJS_B)

fclean:		clean
			make fclean -C ./printf
			rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re

