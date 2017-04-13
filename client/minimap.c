/*
** minimap.c for minimap in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Dec 19 12:55:26 2016 Arthur Knoepflin
** Last update Wed Jan  4 21:16:43 2017 
*/

#include <math.h>
#include "wolf.h"

void	draw_square(t_frame *frame,
		    sfVector2i origin,
		    sfVector2i end,
		    sfColor color)
{
  int	i;
  int	j;

  i = origin.y;
  j = origin.x;
  while (i < end.y)
    {
      j = origin.x;
      while (j < end.x)
	{
	  my_put_pixel(frame, i, j, color);
	  j += 1;
	}
      i += 1;
    }
}

void		draw_field_view(t_frame *frame, t_parse *in, t_ply *ply)
{
  sfVector2i	org;
  sfVector2i	end;
  sfVector2i	sizemap;
  float		rc;
  float		i;

  i = 0.0;
  while (i < ply->fov)
    {
      org.y = (((float)(MAP_W / in->height)) * ply->pos.y);
      org.x = (((float)(MAP_H / in->width)) * ply->pos.x);
      rc = raycast(ply->pos, i + (ply->angle - (ply->fov / 2)),
		   in->data, in->sizemap);
      end.x = org.x + ((rc * (MAP_W / in->width)) *
		       cosd(i + (ply->angle - (ply->fov / 2))));
      end.y = org.y - ((rc * (MAP_H / in->height)) *
		       sind(i + (ply->angle - (ply->fov / 2))));
      my_draw_line(frame, org, end, sfRed);
      i += 0.1;
    }
}

void		draw_ply(t_frame *frame, t_parse *in, t_ply *ply)
{
  sfVector2i	org;
  sfVector2i	end;

  org.y = (((float)(MAP_H / in->width)) * ply->pos.x) - 5;
  org.x = (((float)(MAP_W / in->height)) * ply->pos.y) - 5;
  end.x = org.x + 10;
  end.y = org.y + 10;
  draw_square(frame, org, end, sfRed);
  draw_field_view(frame, in, ply);
}

void		minimap(t_frame *frame, t_parse *in, t_ply *ply)
{
  int		i;
  int		j;
  sfVector2i	origin;
  sfVector2i	end;

  i = 0;
  while (i < in->height)
    {
      j = 0;
      while (j < in->width)
	{
	  if (in->data[i][j] != 0)
	    {
	      origin.x = ((float) ((float) (MAP_H / in->height)) * i);
	      origin.y = ((float) ((float) (MAP_W / in->width)) * j);
	      end.x = origin.x + (MAP_H / in->height);
	      end.y = origin.y + (MAP_W / in->width);
	      draw_square(frame, origin, end, sfBlue);
	    }
	  j += 1;
	}
      i += 1;
    }
  draw_ply(frame, in, ply);
}
