/*
** my_put_pixel.c for my_put_pixel in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Nov 23 08:23:36 2016 Arthur Knoepflin
** Last update Mon Dec 19 11:12:11 2016 Arthur Knoepflin
*/

#include <SFML/Graphics.h>
#include "wolf.h"

void	my_put_pixel(t_my_framebuffer *buffer, int x, int y, sfColor color)
{
  if (x >= 0 && x < buffer->width && y >= 0 && y < buffer->height)
    {
      buffer->pixels[(buffer->width * y + x) * 4] = (int) color.r;
      buffer->pixels[(buffer->width * y + x) * 4 + 1] = (int) color.g;
      buffer->pixels[(buffer->width * y + x) * 4 + 2] = (int) color.b;
      buffer->pixels[(buffer->width * y + x) * 4 + 3] = (int) color.a;
    }
}
