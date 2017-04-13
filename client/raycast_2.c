/*
** raycast_2.c for raycast_2 in /home/arthur/wolf3d_4/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Dec 28 11:45:54 2016 Arthur Knoepflin
** Last update Fri Jan  6 15:49:33 2017 
*/

#include <SFML/Graphics.h>
#include "wolf.h"

sfVector2f	ret_inf()
{
  sfVector2f	ret;

  ret.x = -1;
  ret.y = -1;
  return (ret);
}

float	get_offset(sfVector2f pos_ver,
		   sfVector2f pos_hor,
		   int side,
		   sfVector2f pos)
{
  float	offset;

  if (side == 0)
    offset = (float) ((pos_ver.y + pos.y) -
		      (int) (pos_ver.y + pos.y));
  else if (side == 1)
    offset = (float) ((pos_hor.x + pos.x) -
		      (int) (pos_hor.x + pos.x));
  if (offset < 0)
    offset *= -1;
  return (offset);
}

int		get_type_wall_ver(sfVector2f pos_hor,
				  sfVector2f pos_ver,
				  t_ply *ply,
				  int **map)
{
  sfVector2i	pos;

  pos.y = (int) (pos_ver.y + ply->pos.y);
  pos.x = (int) (pos_ver.x + ply->pos.x);
  if (cosd(ply->direction) >= 0 && pos.y < ply->ms.x && pos.x < ply->ms.y &&
      pos.x >= 0 && pos.y >= 0)
    return (map[pos.y][pos.x] - 1);
  else if (pos.y < ply->ms.x && pos.x < ply->ms.y &&
	   pos.x >= 1 && pos.y >= 0)
    return (map[pos.y][pos.x - 1] - 1);
}

int		get_type_wall_hor(sfVector2f pos_hor,
				  sfVector2f pos_ver,
				  t_ply *ply,
				  int **map)
{
  sfVector2i	pos;

  pos.y = (int) (pos_hor.y + ply->pos.y);
  pos.x = (int) (pos_hor.x + ply->pos.x);
  if (sind(ply->direction) < 0 && pos.y < ply->ms.x && pos.x < ply->ms.y &&
      pos.x >= 0 && pos.y >= 0)
    return (map[pos.y][pos.x] - 1);
  else if (pos.y < ply->ms.x && pos.x < ply->ms.y &&
	   pos.x >= 0 && pos.y >= 1)
    return (map[pos.y - 1][pos.x] - 1);
}

int		get_type_wall(sfVector2f pos_hor,
			      sfVector2f pos_ver,
			      t_ply *ply,
			      int **map)
{
  int		ret;
  sfVector2i	pos;

  ret = 0;
  if (ply->side == 0)
    ret = get_type_wall_ver(pos_hor, pos_ver, ply, map);
  else
    ret = get_type_wall_hor(pos_hor, pos_ver, ply, map);
  if (ret < 0)
    ret = 0;
  if (ret > 7)
    ret = 7;
  return (ret);
}
