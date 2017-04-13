/*
** color.c for color in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Dec 20 21:43:09 2016 Arthur Knoepflin
** Last update Sat Dec 31 11:53:05 2016 Arthur Knoepflin
*/

#include <SFML/Graphics.h>

sfColor		ground_color()
{
  sfColor	ret;

  ret.r = 153;
  ret.g = 153;
  ret.b = 51;
  ret.a = 255;
  return (ret);
}

sfColor		sky_color()
{
  sfColor	ret;

  ret.r = 51;
  ret.g = 102;
  ret.b = 204;
  ret.a = 255;
  return (ret);
}
