/*
** fire.c for fire in /home/arthur/wolf3d_5/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Dec 30 16:15:19 2016 Arthur Knoepflin
** Last update Tue Jan 10 22:33:44 2017 
*/

#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <time.h>
#include "wolf.h"
#include "my.h"

void	fire_usp(t_ply *ply)
{
  char	buffer[BUF_SIZE];

  if (ply->fire->time < get_tick() - 500)
    {
      write_server(ply->sock, "<FIRE>1;2");
      read_server(ply->sock, buffer);
      if (my_strcmp(buffer, "<OK>") == 0)
	sfMusic_play(ply->fire->hit_sound);
      else if (my_strcmp(buffer, "<NOPE>") == 0)
	sfMusic_play(ply->fire->sound);
      if (my_strcmp(buffer, "<KO>") != 0)
	ply->fire->time = get_tick();
    }
}

void	fire_awp(t_ply *ply)
{
  char	buffer[BUF_SIZE];

  if (ply->fire->time < get_tick() - 1000)
    {
      sprintf(buffer, "<FIRE>2;%d\n", ply->fire->act_weap - 1);
      write_server(ply->sock, buffer);
      read_server(ply->sock, buffer);
      if (my_strcmp(buffer, "<OK>") == 0)
	sfMusic_play(ply->fire->awp_hit);
      else if (my_strcmp(buffer, "<NOPE>") == 0)
	sfMusic_play(ply->fire->awp);
      if (my_strcmp(buffer, "<KO>") != 0)
	ply->fire->time = get_tick();
    }

}

void	fire(t_ply *ply)
{
  if (sfMouse_isButtonPressed(sfMouseLeft))
    {
      if (ply->fire->act_weap == 1)
	fire_usp(ply);
      else
	fire_awp(ply);
    }
}
