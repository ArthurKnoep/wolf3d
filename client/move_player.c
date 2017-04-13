/*
** move_player.c for move_player in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Dec 19 13:54:22 2016 Arthur Knoepflin
** Last update Fri Jan 13 16:27:37 2017 
*/

#include <math.h>
#include "wolf.h"

void		move_forward(t_ply *ply, t_parse *in)
{
  double	speed;
  sfVector2f	pos_next;

  speed = 0.06;
  pos_next.x = ply->pos.x + speed * cos(((float)(ply->angle * M_PI) / 180));
  if (cosd(ply->angle) >= 0 &&
      in->data[(int) ply->pos.y][(int) (pos_next.x + 0.1)] == 0)
    ply->pos.x = pos_next.x;
  else if (cosd(ply->angle) < 0 &&
	   in->data[(int) ply->pos.y][(int) (pos_next.x - 0.1)] == 0)
    ply->pos.x = pos_next.x;
  pos_next.y = ply->pos.y - speed * sin(((float)(ply->angle * M_PI) / 180));
  if (sind(ply->angle) >= 0 &&
      in->data[(int) (pos_next.y - 0.1)][(int) ply->pos.x] == 0)
    ply->pos.y = pos_next.y;
  else if (sind(ply->angle) < 0 &&
	   in->data[(int) (pos_next.y + 0.1)][(int) ply->pos.x] == 0)
    ply->pos.y = pos_next.y;
}

void	move_backward(t_ply *ply, t_parse *in)
{
  float	angle;

  angle = ply->angle;
  ply->angle -= 180;
  move_forward(ply, in);
  ply->angle= angle;
}

void	move_left(t_ply *ply, t_parse *in)
{
  float	angle;

  angle = ply->angle;
  ply->angle += 90;
  move_forward(ply, in);
  ply->angle = angle;
}

void	move_right(t_ply *ply, t_parse *in)
{
  float	angle;

  angle = ply->angle;
  ply->angle -= 90;
  move_forward(ply, in);
  ply->angle = angle;
}

void		move_player(t_ply *ply, t_parse *in, t_var *var)
{
  sfVector2i	mouse_act;

  if (ply->life > 0)
    {
      mouse_act = sfMouse_getPosition((sfWindow *) var->win);
      ply->angle += ((float) (var->mouse.x - mouse_act.x)) / ply->speed_mouse;
      sfMouse_setPosition(var->mouse, (sfWindow *) var->win);
      if (sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyZ))
	move_forward(ply, in);
      else if (sfKeyboard_isKeyPressed(sfKeyDown) ||
	       sfKeyboard_isKeyPressed(sfKeyS))
	move_backward(ply, in);
      if (sfKeyboard_isKeyPressed(sfKeyQ))
	move_left(ply, in);
      else if (sfKeyboard_isKeyPressed(sfKeyD))
	move_right(ply, in);
      if (sfKeyboard_isKeyPressed(sfKeyLeft))
	ply->angle += 3;
      else if (sfKeyboard_isKeyPressed(sfKeyRight))
	ply->angle -= 3;
      move_player_2(ply, var);
    }
}
