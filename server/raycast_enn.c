/*
** raycast_enn.c for raycast_enn in /home/arthur/wolf3d_4/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 29 14:33:23 2016 Arthur Knoepflin
** Last update Tue Jan 10 21:25:54 2017 
*/

#include <math.h>
#include <SFML/Window.h>
#include "server.h"

float		raycast_enn(t_client pos, t_client enn)
{
  sfVector2f	vect;

  vect.x = enn.x - pos.x;
  vect.y = enn.y - pos.y;
  return (sqrt(pow(vect.x, 2) + pow(vect.y, 2)));
}

static float	angle_1(t_client pos, t_client enn)
{
  sfVector2f	pos_fict;
  sfVector2f	vect;
  float		angle;

  pos_fict.x = pos.x + 4 * cosd(pos.angle);
  pos_fict.y = pos.y + -4 * sind(pos.angle);
  vect.y = pos_fict.x - pos.x;
  vect.x = pos_fict.y - pos.y;
  angle = atan(vect.x / vect.y) * 180 / M_PI;
  if (vect.y < 0)
    angle += 180;
  if (angle >= 180)
    angle -= 360;
  return (angle);
}

float		angle_enn(t_client pos, t_client enn)
{
  sfVector2f	vect1;
  float		angle1;
  float		angle2;

  angle1 = angle_1(pos, enn);
  vect1.x = enn.x - pos.x;
  vect1.y = enn.y - pos.y;
  angle2 = atan(vect1.y / vect1.x) * 180 / M_PI;
  if (vect1.x < 0)
    angle2 += 180;
  if (angle2 >= 180)
    angle2 -= 360;
  return (angle2 - angle1);
}

int		is_visible(t_client pos, t_client enn, t_parse *in)
{
  sfVector2f	vect1;
  float		angle;
  float		rc_wall;
  float		rc_enn;

  vect1.x = enn.x - pos.x;
  vect1.y = enn.y - pos.y;
  angle = atan(vect1.y / vect1.x) * 180 / M_PI;
  if (vect1.x < 0)
    angle += 180;
  if (angle >= 180)
    angle -= 360;
  rc_wall = raycast(pos, -1 * angle, in->data, in->sizemap);
  rc_enn = raycast_enn(pos, enn);
  if ((rc_wall + 2) >= rc_enn)
    return (1);
  else
    return (0);
}
