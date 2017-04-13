/*
** raycast_enn.c for raycast_enn in /home/arthur/wolf3d_4/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 29 14:33:23 2016 Arthur Knoepflin
** Last update Tue Jan 10 15:22:18 2017 
*/

#include <math.h>
#include "wolf.h"

float		raycast_enn(sfVector2f pos, t_pos pos_enn)
{
  float		ret;
  sfVector2f	vect;

  vect.x = pos_enn.x - pos.y;
  vect.y = pos_enn.y - pos.x;
  ret = sqrt(pow(vect.x, 2) + pow(vect.y, 2));
  return (ret);
}

static float	angle_1(t_ply *ply, sfVector2f pos)
{
  sfVector2f	pos_fict;
  sfVector2f	vect;
  float		angle;

  pos_fict.x = pos.x + 4 * cosd(ply->angle);
  pos_fict.y = pos.y + -4 * sind(ply->angle);
  vect.y = pos_fict.x - pos.x;
  vect.x = pos_fict.y - pos.y;
  angle = atan(vect.x / vect.y) * 180 / M_PI;
  if (vect.y < 0)
    angle += 180;
  if (angle >= 180)
    angle -= 360;
  return (angle);
}

float		angle_enn(t_ply *ply, sfVector2f pos, t_pos pos_enn)
{
  sfVector2f	vect1;
  float		angle1;
  float		angle2;

  angle1 = angle_1(ply, pos);
  vect1.x = pos_enn.x - pos.y;
  vect1.y = pos_enn.y - pos.x;
  angle2 = atan(vect1.x / vect1.y) * 180 / M_PI;
  if (vect1.y < 0)
    angle2 += 180;
  if (angle2 >= 180)
    angle2 -= 360;
  return (angle2 - angle1);
}

int		is_visible(t_ply *ply, sfVector2f pos, t_pos pos_enn, t_parse *in)
{
  sfVector2f	vect1;
  float		angle;
  float		rc_wall;
  float		rc_enn;

  vect1.x = pos_enn.x - pos.y;
  vect1.y = pos_enn.y - pos.x;
  angle = atan(vect1.x / vect1.y) * 180 / M_PI;
  if (vect1.y < 0)
    angle += 180;
  if (angle >= 180)
    angle -= 360;
  rc_wall = raycast(pos, -1 * angle, in->data, in->sizemap);
  rc_enn = raycast_enn(pos, pos_enn);
  if (rc_wall >= rc_enn)
    return (1);
  else
    return (0);
}
