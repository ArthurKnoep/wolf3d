/*
** sky.c for sky in /home/arthur/wolf3d_6/client
** 
** Made by 
** Login   <arthur@epitech.net>
** 
** Started on  Fri Jan  6 17:07:31 2017 
** Last update Fri Jan  6 18:14:35 2017 
*/

#include <SFML/Graphics.h>
#include "wolf.h"

void		draw_sky(t_frame *frame, t_ply *ply, sfVector2i pos_px)
{
  float		fov;
  float		angle;
  float		direction;
  sfVector2f	rt_sky;

  rt_sky.x = (float) (HEIGHT / 2) / (float) ply->sky->height;
  rt_sky.y = (float) ply->sky->width / 360;
  fov = ((float) ply->fov / WIDTH);
  angle = (int) ply->angle % 360;
  if (angle < 0)
    angle += 360;
  direction = (int) ((pos_px.y * fov) + angle - ply->fov / 2) % 360;
  if (direction < 0)
    direction += 360;
  my_put_pixel(frame, WIDTH - pos_px.y, pos_px.x,
	       get_color((float) pos_px.x * rt_sky.x,
			 direction * (float) rt_sky.y, ply->sky));
}
