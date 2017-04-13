/*
** draw_mp_2.c for draw_mp_2 in /home/arthur/wolf3d_5/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sun Jan  1 18:56:43 2017 Arthur Knoepflin
** Last update Tue Jan 10 15:22:02 2017 
*/

#include <SFML/Graphics.h>
#include "wolf.h"

void	get_size_img(sfVector2i *size_img, t_ply *ply)
{
  float	ratio;

  if (ply->pos_ply[ply->i].life == 0)
    {
      ratio = (float) size_img->x / (float) ply->enn_dead->height;
      size_img->y = (int) ((float) ply->enn_dead->width * ratio);
    }
  else
    {
      ratio = (float) size_img->x / (float) ply->text_enn->height;
      size_img->y = (int) ((float) ply->text_enn->width * ratio);
    }
  size_img->x *= ply->zoom;
  size_img->y *= ply->zoom;
}
