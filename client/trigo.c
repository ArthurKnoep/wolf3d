/*
** trigo.c for trigo in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Dec 19 22:38:08 2016 Arthur Knoepflin
** Last update Mon Dec 19 22:39:50 2016 Arthur Knoepflin
*/

#include <math.h>

double	cosd(double val)
{
  return (cos(val * M_PI / 180));
}

double	sind(double val)
{
  return (sin(val * M_PI / 180));
}

double	tand(double val)
{
  return (tan(val * M_PI / 180));
}
