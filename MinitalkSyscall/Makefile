# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                          :+:     :+:             #
#                                                     +:+ +:+         +:+      #
#    By: thfirmin <thfirmin@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 21:43:07 by thfirmin          #+#    #+#              #
#    Updated: 2022/08/22 21:54:06 by Thinotsuki   ###     ###.br               #
#                                                                              #
# **************************************************************************** #

# +>                                     NAMES 

NAME		= minitalk

CLIENT		= client

SERVER		= server

LIBFT		= libft.a

LIBFT_DIR	= libft/
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     SRCS 

CLT_SRCS	= client.o

SRV_SRCS	= server.o

CLT_OBJS	= $(CLT_SRCS:.c=.o)

SRV_OBJS	= $(SRV_SRCS:.c=.o)
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                    ALIASES 

AR			= ar rcs
RM			= rm -rf
CC			= cc
MAKE		= make -C
CFLAGS		= -g -Wall -Wextra -Werror
#MAKEFLAGS	+= --silent
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                   TXT CODE 

BLANK			= \e[m
RED				= \e[38;5;9m
YELLOW			= \e[38;5;11m
GREEN			= \e[38;5;2m
BLUE			= \e[38;5;6m
PURPLE			= \e[38;5;5m
PINK			= \e[38;5;13m
WHITE			= \e[38;5;15m

STRONG			= \e[1m
SHADOW			= \e[2m
ITALIC			= \e[3m
UNDLINE			= \e[4m
UPPLINE			= \e[53m
DUNDLINE		= \e[21m
CENSORED		= \e[9m
UPALIGN			= \e[73m
DWALIGN			= \e[74m
FULLER			= \e[7m
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# +>                                     RULES 

all:		$(NAME)

$(NAME):	$(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):	$(LIBFT_DIR)$(LIBFT)
	cp $(LIBFT_DIR)$(LIBFT) ./

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) $(LIBFT_DIR)

$(CLIENT):	$(CLT_OBJS)
	$(CC) $(CFLAGS) $(CLT_OBJS) $(LIBFT) -o $(CLIENT)

$(SERVER):	$(SRV_OBJS)
	$(CC) $(CFLAGS) $(SRV_OBJS) $(LIBFT) -o $(SERVER)

clean:
	$(RM) $(CLT_OBJS)
	$(RM) $(SRV_OBJS)
	$(MAKE) $(LIBFT_DIR) clean

fclean:
	$(RM) $(CLT_OBJS) $(SRV_OBJS)
	$(RM) $(SERVER) $(CLIENT) $(LIBFT)
	$(MAKE) $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
# <+-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-' #
# vim: fdm=marker fmr=+>,<+ ts=4 sw=4 nofen noet:
