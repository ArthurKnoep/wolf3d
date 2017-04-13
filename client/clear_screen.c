/*
** clear_screen.c for clear_screen in /home/arthur/delivery/MUL/wireframe
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Nov 22 23:55:18 2016 Arthur Knoepflin
** Last update Mon Dec 19 10:43:01 2016 Arthur Knoepflin
*/

#include <SFML/Graphics.h>
#include "wolf.h"

void	clear_screen(t_frame *frame, sfColor color)
{
  int	i;
  int	j;

  i = 0;
  while (i < frame->height)
    {
      j = 0;
      while (j < frame->width)
	{
	  my_put_pixel(frame, j, i, color);
	  j += 1;
	}
      i += 1;
    }
}

void	clear_scr(sfRenderWindow *window, t_frame *frame)
{
  sfRenderWindow_clear(window, sfBlack);
  clear_screen(frame, sfBlack);
}

void	draw_on_scr(sfRenderWindow **window,
		    sfTexture **texture,
		    sfSprite **sprite,
		    t_frame *frame)
{
  sfTexture_updateFromPixels(*texture, frame->pixels, WIDTH, HEIGHT, 0, 0);
  sfRenderWindow_drawSprite(*window, *sprite, NULL);
  sfRenderWindow_display(*window);
}
