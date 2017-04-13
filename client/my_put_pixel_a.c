/*
** my_put_pixel.c for my_put_pixel in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Nov 23 08:23:36 2016 Arthur Knoepflin
** Last update Sat Dec 31 11:51:20 2016 Arthur Knoepflin
*/

#include <SFML/Graphics.h>
#include "wolf.h"

void	my_put_pixel_hit(t_my_framebuffer *buffer, int x, int y)
{
  if (x >= 0 && x < buffer->width && y >= 0 && y < buffer->height)
    {
      if (buffer->pixels[(buffer->width * y + x) * 4] + 50 > 255)
	buffer->pixels[(buffer->width * y + x) * 4] = 255;
      else
	buffer->pixels[(buffer->width * y + x) * 4] += 50;
    }
}
