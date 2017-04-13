/*
** my_framebuffer.c for my_framebuffer in /home/arthur/delivery/MUL/Bootstrap_1
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Tue Nov 15 13:21:22 2016 Arthur Knoepflin
** Last update Mon Dec 19 10:47:12 2016 Arthur Knoepflin
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "wolf.h"

t_frame		*my_frame_create(int width, int height)
{
  t_frame	*ret;
  int		i;

  i = 0;
  ret = malloc(sizeof(*ret));
  ret->pixels = malloc(sizeof(*(ret->pixels)) * width * height * 4);
  while (i < width * height * 4)
    {
      ret->pixels[i] = 0;
      i += 1;
    }
  ret->width = width;
  ret->height = height;
  return (ret);
}

void	my_frame_destroy(t_frame *fb)
{
  free(fb->pixels);
  free(fb);
}
