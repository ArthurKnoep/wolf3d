/*
** draw_mp.c for draw_mp.c in /home/arthur/wolf3d_3/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sun Dec 25 19:08:56 2016 Arthur Knoepflin
** Last update Fri Jan  6 16:51:38 2017 
*/

#include "wolf.h"

void		draw_all_player(t_frame *frame, t_parse *in, t_pos *pos, t_ply *ply)
{
  int		i;
  sfVector2i	start;
  sfVector2i	end;

  i = 0;
  if (pos != NULL)
    while (i < ply->nb_player)
      {
	start.y = (((float)(MAP_W / in->width)) * pos[i].y) - 5;
	start.x = (((float)(MAP_H / in->height)) * pos[i].x) - 5;
	end.x = start.x + 10;
	end.y = start.y + 10;
	draw_square(frame, start, end, sfGreen);
	i += 1;
      }
}

void		draw_all_view(t_frame *frame, t_parse *in, t_pos *pos, t_ply *ply)
{
  int		i;
  sfVector2i	start;
  sfVector2i	end;

  i = 0;
  if (pos != NULL)
    while (i < ply->nb_player)
      {
	start.x = (((float)(MAP_W / in->width)) * pos[i].y);
	start.y = (((float)(MAP_H / in->height)) * pos[i].x);
	end.y = start.y + -50 * sind(pos[i].angle);
	end.x = start.x + 50 * cosd(pos[i].angle);
	my_draw_line(frame, start, end, sfGreen);
	i += 1;
      }
}

void		draw_text(t_frame *frame,
			  sfVector2i start,
			  sfVector2i end,
			  t_frame *text)
{
  int		i;
  sfVector2f	ratio;
  sfColor	color;
  int		j;

  i = start.y;
  ratio.y = (float) text->width / (float) (end.y - start.y);
  ratio.x = (float) text->height / (float) (end.x - start.x);
  while (i < end.y)
    {
      j = start.x;
      while (j < end.x)
	{
	  color = get_color((float) (j - start.x) * ratio.x,
			    (float) (i - start.y) * ratio.y, text);
	  if (color.a != 0)
	    my_put_pixel(frame, i, j, color);
	  j += 1;
	}
      i += 1;
    }
}

void		draw_enn(t_frame *frame,
			 t_ply *ply,
			 sfVector2i size_img,
			 float angle)
{
  float		fov;
  sfVector2i	pos_img;
  sfVector2i	end;

  fov = (float) (WIDTH) / ply->fov;
  pos_img.y = (fov * angle + (WIDTH / 2)) - (size_img.y / 2);
  pos_img.x = (HEIGHT / 2) - (size_img.x / 2);
  pos_img.x += 10;
  end.y = pos_img.y + size_img.y;
  end.x = pos_img.x + size_img.x;
  if (ply->pos_ply[ply->i].life == 0)
    draw_text(frame, pos_img, end, ply->enn_dead);
  else
    draw_text(frame, pos_img, end, ply->text_enn);
}

void		draw_skin(t_frame *frame, t_ply *ply, t_parse *parse)
{
  sfVector2i	size_img;
  float		rc;
  float		angle;

  ply->i = 0;
  if (ply->pos_ply != NULL)
    while (ply->i < ply->nb_player)
      {
	rc = raycast_enn(ply->pos, ply->pos_ply[ply->i]);
	angle = angle_enn(ply, ply->pos, ply->pos_ply[ply->i]);
	rc *= cosd(angle);
	size_img.x = HEIGHT;
	if (rc != 0)
	  size_img.x = (int) ((float) HEIGHT / rc);
	get_size_img(&size_img, ply);
	if (angle >= -1 * (ply->fov / 2) && angle <= ply->fov / 2)
	  if (is_visible(ply, ply->pos, ply->pos_ply[ply->i], parse))
	    draw_enn(frame, ply, size_img, angle);
	ply->i += 1;
      }
}
