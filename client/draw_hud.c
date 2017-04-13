/*
** draw_hud.c for draw_hud in /home/arthur/wolf3d_4/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 29 12:13:21 2016 Arthur Knoepflin
** Last update Tue Jan 10 14:59:03 2017 
*/

#include "wolf.h"

void		draw_ver(t_frame *frame)
{
  sfVector2i	start;
  sfVector2i	end;

  start.x = (HEIGHT / 2) - 35;
  start.y = (WIDTH / 2) - 2;
  end.x = start.x + 25;
  end.y = start.y + 4;
  draw_square(frame, start, end, sfGreen);
  start.x = (HEIGHT / 2) + 10;
  end.x = start.x + 25;
  draw_square(frame, start, end, sfGreen);
}

void		draw_hor(t_frame *frame)
{
  sfVector2i	start;
  sfVector2i	end;

  start.x = (HEIGHT / 2) - 2;
  end.x = start.x + 4;
  start.y = (WIDTH / 2) - 35;
  end.y = start.y + 25;
  draw_square(frame, start, end, sfGreen);
  start.y = (WIDTH / 2) + 10;
  end.y = start.y + 25;
  draw_square(frame, start, end, sfGreen);
}

void	draw_hit(t_frame *frame, t_ply *ply)
{
  int	i;
  int	j;

  if (ply->life == 1)
    {
      i = 0;
      while (i < frame->height)
	{
	  j = 0;
	  while (j < frame->width)
	    {
	      my_put_pixel_hit(frame, j, i);
	      j += 1;
	    }
	  i += 1;
	}
    }
}

void		draw_hud(t_frame *frame, t_ply *ply)
{
  sfVector2i	start;
  sfVector2i	end;

  if (ply->fire->act_weap == 1)
    {
      draw_ver(frame);
      draw_hor(frame);
    }
  start.x = 0;
  start.y = 0;
  end.x = HEIGHT;
  end.y = WIDTH;
  if (ply->fire->act_weap == 1)
    if (ply->fire->time < get_tick() - 100)
      draw_text(frame, start, end, ply->hud);
    else
      draw_text(frame, start, end, ply->fire_hud);
  else if (ply->fire->act_weap == 2)
    if (ply->fire->time < get_tick() - 100)
      draw_text(frame, start, end, ply->awp);
    else
      draw_text(frame, start, end, ply->awp_hud);
  else if (ply->fire->act_weap == 3)
    draw_text(frame, start, end, ply->dot_red);
  draw_hit(frame, ply);
}
