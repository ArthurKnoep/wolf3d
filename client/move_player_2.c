/*
** kill_all.c for kill_all.c in /home/arthur/wolf3d_5/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Jan  2 15:52:34 2017 Arthur Knoepflin
** Last update Fri Jan 13 16:36:21 2017 
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include "wolf.h"

void		move_player_3(t_ply *ply, t_var *var)
{
  sfEvent	event;

  while (sfRenderWindow_pollEvent(var->win, &event))
    {
      if (event.type == sfEvtMouseWheelScrolled)
  	{
	  if (ply->fire->act_weap == 2 || ply->fire->act_weap == 3)
	    {
	      if (ply->fire->act_weap == 3)
		ply->zoom = 1;
	      ply->fire->act_weap = 1;
	    }
	  else if (ply->fire->act_weap == 1)
	    ply->fire->act_weap = 2;
  	}
      if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
	sfRenderWindow_close(var->win);
    }
}

void		move_player_2(t_ply *ply, t_var *var)
{
  char		buf[BUF_SIZE];

  if (sfKeyboard_isKeyPressed(sfKeyO))
    {
      write_server(ply->sock, "<KILL_ALL>");
      read_server(ply->sock, buf);
    }
  if (sfMouse_isButtonPressed(sfMouseRight) && ply->fire->act_weap >= 2 &&
      ply->fire->zoom_time < get_tick() - 300)
    {
      ply->zoom = (ply->zoom == 1) ? 5 : 1;
      ply->speed_mouse = (ply->fire->act_weap == 2) ? 50 : 10;
      ply->fire->act_weap = (ply->fire->act_weap == 2) ? 3 : 2;
      ply->fire->zoom_time = get_tick();
      sfMusic_play(ply->fire->zoom);
    }
  move_player_3(ply, var);
}
