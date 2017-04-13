##
## Makefile for Makefile in /home/arthur/delivery/MUL/wolf3d
## 
## Made by Arthur Knoepflin
## Login   <arthur@epitech.net>
## 
## Started on  Mon Dec 19 09:59:53 2016 Arthur Knoepflin
## Last update Tue Jan 10 22:57:17 2017 
##

SRC	=	check_stru_syn.c	\
		clear_screen.c		\
		color.c			\
		com.c			\
		connection.c		\
		create_window.c		\
		draw.c			\
		draw_hud.c		\
		draw_mp.c		\
		draw_mp_2.c		\
		sky.c			\
		fire.c			\
		game_over.c		\
		init_player.c		\
		main.c			\
		minimap.c		\
		move_player.c		\
		move_player_2.c		\
		my_frame.c		\
		my_put_pixel_a.c	\
		parse.c			\
		parse_2.c		\
		pos.c			\
		pos_2.c			\
		put_error.c		\
		read_file.c		\
		src/my_put_pixel.c	\
		src/my_draw_line.c	\
		src/raycast.c		\
		time.c			\
		raycast.c		\
		raycast_2.c		\
		raycast_enn.c		\
		size_file.c		\
		texture/color.c		\
		texture/fill_stru.c	\
		texture/load_texture.c	\
		texture/read_xpm.c	\
		trigo.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wolf3d

INCLUDE	=	include

TEXTURE	=	texture/file

LIB	=	lib

LIB_N	=	my

# CFLAGS	+=	-I$(INCLUDE) -I$(TEXTURE) -g -Wall -Wextra
CFLAGS	+=	-I$(INCLUDE) -I$(TEXTURE) -lc_graph_prog -lm -O2

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -l$(LIB_N) -L$(LIB) -lc_graph_prog -lm

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
