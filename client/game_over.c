/*
** game_over.c for game_over in /home/arthur/wolf3d_5/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sat Dec 31 12:00:26 2016 Arthur Knoepflin
** Last update Fri Jan  6 14:14:48 2017 
*/

#include <SFML/Window.h>
#include <stdlib.h>
#include <time.h>
#include "wolf.h"

static void	draw_msg(t_frame *frame, t_ply *ply)
{
  sfVector2i	start;
  sfVector2i	end;

  start.x = 0;
  start.y = 0;
  end.x = HEIGHT;
  end.y = WIDTH;
  draw_text(frame, start, end, ply->go);
}

void		game_over(t_frame *frame, t_ply *ply, t_parse *parse)
{
  sfVector2f	pos;
  char		buffer[BUF_SIZE];

  draw_msg(frame, ply);
  if (sfKeyboard_isKeyPressed(sfKeyReturn))
    {
      write_server(ply->sock, "<RESPAWN>");
      read_server(ply->sock, buffer);
      srand(time(NULL));
      pos.x = rand() % parse->sizemap.y;
      pos.y = rand() % parse->sizemap.x;
      while (parse->data[(int) pos.y][(int) pos.x] != 0)
	{
	  pos.x = rand() % parse->sizemap.y;
	  pos.y = rand() % parse->sizemap.x;
	}
      ply->life = 2;
      pos.x += 0.5;
      pos.y += 0.5;
      ply->pos = pos;
      send_pos(ply, 0);
    }
}
