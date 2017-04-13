/*
** create_window.c for create_window in /home/arthur/delivery/MUL/wireframe
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Nov 21 23:15:20 2016 Arthur Knoepflin
** Last update Sun Jan  1 19:05:01 2017 Arthur Knoepflin
*/

#include <SFML/Graphics.h>
#include "wolf.h"

sfRenderWindow		*create_window(int height, int width, char *title)
{
  sfVideoMode		mode;
  sfRenderWindow	*window;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, title, sfClose, NULL);
  sfRenderWindow_setMouseCursorVisible(window, sfFalse);
  return (window);
}
