##
## Makefile for Makefile in /home/arthur/wolf3d_3/server
## 
## Made by Arthur Knoepflin
## Login   <arthur@epitech.net>
## 
## Started on  Thu Dec 22 09:55:27 2016 Arthur Knoepflin
## Last update Mon Jan  2 22:03:30 2017 Arthur Knoepflin
##

SRC	=	conf/check_error.c	\
		conf/conf.c		\
		conf/fill_stru.c	\
		conf/fill_stru_fnt.c	\
		conf/read_file.c	\
		init_connection.c	\
		fire.c			\
		kill_all.c		\
		main.c			\
		client.c		\
		client_msg.c		\
		check_pos.c		\
		my_strncmp.c		\
		parse.c			\
		parse_2.c		\
		pos.c			\
		trigo.c			\
		read_client.c		\
		read_file.c		\
		raycast.c		\
		raycast_enn.c		\
		size_file.c		\
		stop.c			\
		time.c

OBJ	=	$(SRC:.c=.o)

NAME	=	server

LIB	=	lib

LIB_N	=	my

INCLUDE	=	include

# CFLAGS	+=	-I$(INCLUDE) -Wall -Wextra -Werror
CFLAGS	+=	-I$(INCLUDE) -g

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -l$(LIB_N) -L$(LIB) -lm -lc_graph_prog

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
