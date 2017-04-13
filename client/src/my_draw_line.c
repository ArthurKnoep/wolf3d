/*
** my_draw_line.c for my_draw_line in /home/arthur/delivery/MUL/wolf
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Nov 23 08:26:59 2016 Arthur Knoepflin
** Last update Mon Dec 19 11:12:34 2016 Arthur Knoepflin
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

void		my_draw_line(t_my_framebuffer *buffer,
			     sfVector2i from,
			     sfVector2i to,
			     sfColor color)
{
  sfVector2f    vector;
  sfVector2i    put;
  int           i;
  float		norme;

  i = 0;
  vector.x = to.x - from.x;
  vector.y = to.y - from.y;
  norme = sqrt(pow(vector.x, 2) + pow(vector.y, 2));
  vector.x /= norme;
  vector.y /= norme;
  while (i < norme)
    {
      put.x = from.x + i * vector.x;
      put.y = from.y + i * vector.y;
      my_put_pixel(buffer, put.x, put.y, color);
      i += 1;
    }
  my_put_pixel(buffer, to.x, to.y, color);
}
