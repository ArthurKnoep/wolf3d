/*
** raycast_2.c for raycast in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Dec 19 20:34:49 2016 Arthur Knoepflin
** Last update Fri Jan 13 16:58:49 2017 
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

float		calc_hor(sfVector2f pos,
			 float direction,
			 int **map,
			 sfVector2i mapsize)
{
  sfVector2f	p_act;
  sfVector2f	p_inc;

  if (cosd(direction) == -1 || cosd(direction) == 1)
    return (-1);
  if (sind(direction) >= 0)
    p_act.y = ((int) pos.y) - pos.y;
  else
    p_act.y = 1 + ((int) pos.y) - pos.y;
  p_act.x = -p_act.y / tand(direction);
  if (sind(direction) >= 0)
    p_inc.y = -1;
  else
    p_inc.y = 1;
  p_inc.x = -p_inc.y / tand(direction);
  while  ((int)(pos.y + p_act.y + p_inc.y / 20) < mapsize.x &&
  	  (int)(pos.y + p_act.y + p_inc.y / 20) >= 0 &&
	  (int)(pos.x + p_act.x) < mapsize.y &&
  	  (int)(pos.x + p_act.x) >= 0 &&
	  map[(int) (pos.y + p_act.y + p_inc.y / 20)][(int) (pos.x + p_act.x)] == 0)
    {
      p_act.x += p_inc.x;
      p_act.y += p_inc.y;
    }
  return (sqrt(pow(p_act.x, 2) + pow(p_act.y, 2)));
}

float		calc_ver(sfVector2f pos,
			 float direction,
			 int **map,
			 sfVector2i mapsize)
{
  sfVector2f	p_act;
  sfVector2f	p_inc;

  if (sind(direction) == -1 || sind(direction) == 1)
    return (-1);
  if (cosd(direction) >= 0)
    p_act.x = 1+ ((int) pos.x) - pos.x;
  else
    p_act.x = ((int) pos.x) - pos.x;
  p_act.y = -p_act.x * tand(direction);
  if (cosd(direction) >= 0)
    p_inc.x = 1;
  else
    p_inc.x = -1;
  p_inc.y = -p_inc.x * tand(direction);
  while ((int)(pos.x + p_act.x + p_inc.x / 20) < mapsize.y &&
	 (int)(pos.x + p_act.x + p_inc.x / 20) >= 0 &&
	 (int)(pos.y + p_act.y) < mapsize.x &&
	 (int)(pos.y + p_act.y) >= 0 &&
	 map[(int)(pos.y + p_act.y)][(int)(pos.x + p_act.x + p_inc.x / 20)] == 0)
    {
      p_act.x += p_inc.x;
      p_act.y += p_inc.y;
    }
  return (sqrt(pow(p_act.x, 2) + pow(p_act.y, 2)));
}

float	raycast(sfVector2f pos, float direction, int **map, sfVector2i mapsize)
{
  float	len_hor;
  float	len_ver;

  len_hor = calc_hor(pos, direction, map, mapsize);
  len_ver = calc_ver(pos, direction, map, mapsize);
  if (len_hor == -1)
    return (len_ver);
  if (len_ver == -1)
    return (len_hor);
  if (len_hor < len_ver)
    return (len_hor);
  else
    return (len_ver);
  return (0);
}
