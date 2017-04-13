/*
** raycast_2.c for raycast in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Dec 19 20:34:49 2016 Arthur Knoepflin
** Last update Tue Jan 10 10:44:11 2017 
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "wolf.h"

static sfVector2f	calc_hor(sfVector2f pos,
				 float direction,
				 int **map,
				 sfVector2i mapsize)
{
  sfVector2f		p_act;
  sfVector2f		p_inc;

  if (cosd(direction) == -1 || cosd(direction) == 1)
    return (ret_inf());
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
  	  (int)(pos.y + p_act.y + p_inc.y / 20) > 0 &&
	  (int)(pos.x + p_act.x) < mapsize.y &&
  	  (int)(pos.x + p_act.x) > 0 &&
	  map[(int) (pos.y + p_act.y + p_inc.y / 20)][(int) (pos.x + p_act.x)] == 0)
    {
      p_act.x += p_inc.x;
      p_act.y += p_inc.y;
    }
  return (p_act);
}

static sfVector2f	calc_ver(sfVector2f pos,
				 float direction,
				 int **map,
				 sfVector2i mapsize)
{
  sfVector2f		p_act;
  sfVector2f		p_inc;

  if (sind(direction) == -1 || sind(direction) == 1)
    return (ret_inf());
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
  return (p_act);
}

static float	get_lengthray(float len_hor,
			      float len_ver,
			      sfVector2f pos_hor,
			      sfVector2f pos_ver)
{
  if (pos_hor.x == -1 || pos_hor.y == -1)
    return (len_ver);
  if (pos_ver.x == -1 || pos_ver.y == -1)
    return (len_hor);
  if (len_hor <= len_ver)
    return (len_hor);
  else
    return (len_ver);
  return (0);
}

static int	get_side(float len_hor,
			 float len_ver,
			 sfVector2f pos_hor,
			 sfVector2f pos_ver)
{
  if (pos_hor.x == -1 || pos_hor.y == -1)
    return (0);
  else if (pos_ver.x == -1 || pos_ver.y == -1)
    return (1);
  else
    {
      if (len_hor <= len_ver)
	return (1);
      else
	return (0);
    }
}

t_raycast	raycast_stru(t_ply *ply,
			     float direction,
			     int **map,
			     sfVector2i mapsize)
{
  t_raycast	ret;
  sfVector2f	pos_hor;
  sfVector2f	pos_ver;
  float		len_hor;
  float		len_ver;

  ply->direction = direction;
  ply->ms = mapsize;
  pos_hor = calc_hor(ply->pos, direction, map, mapsize);
  len_hor = sqrt(pow(pos_hor.x, 2) + pow(pos_hor.y, 2));
  pos_ver = calc_ver(ply->pos, direction, map, mapsize);
  len_ver = sqrt(pow(pos_ver.x, 2) + pow(pos_ver.y, 2));
  ret.length = get_lengthray(len_hor, len_ver, pos_hor, pos_ver);
  ret.length *= cosd((-1 * ply->fov / 2) +
  		     (ply->i * (float) ply->fov / WIDTH));
  ret.length /= ply->zoom;
  ret.side = get_side(len_hor, len_ver, pos_hor, pos_ver);
  ply->side = ret.side;
  ret.offset = get_offset(pos_ver, pos_hor, ret.side, ply->pos);
  ret.type_wall = get_type_wall(pos_hor, pos_ver, ply, map);
  if (ret.length != 0)
    ret.height_wall = HEIGHT / ret.length;
  else
    ret.height_wall = HEIGHT;
  return (ret);
}
