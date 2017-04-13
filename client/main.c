/*
** main.c for main in /home/arthur/delivery/MUL/wolf3D
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Mon Nov 21 16:19:38 2016 Arthur Knoepflin
** Last update Fri Jan 13 21:55:04 2017 
*/

#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "wolf.h"
#include "my.h"

void	free_all(t_ply *ply)
{
  sfMusic_destroy(ply->fire->sound);
  free(ply->fire);
  my_frame_destroy(ply->text[0]);
  my_frame_destroy(ply->text_enn);
  my_frame_destroy(ply->hud);
  free(ply);
}

void			main_core(t_var *var,
				  t_parse *parse,
				  t_ply *ply)
{
  t_frame		*frame;
  sfSprite		*sprite;
  sfTexture		*texture;
  unsigned long long	old;
  unsigned long long	clock;
  sfEvent		event;

  sprite = sfSprite_create();
  texture = sfTexture_create(WIDTH, HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  frame = my_frame_create(WIDTH, HEIGHT);
  clock = get_tick();
  while (sfRenderWindow_isOpen(var->win))
    {
      old = get_time();
      clear_scr(var->win, frame);
      draw(frame, parse, ply, var);
      move_player(ply, parse, var);
      draw_on_scr(&(var->win), &texture, &sprite, frame);
      if (clock < get_tick() - 1000)
	{
	  clock = get_tick();
	  printf("FPS : %llu\n", 1000 / (get_time() - old));
	}
    }
  my_frame_destroy(frame);
  sfRenderWindow_destroy(var->win);
}

int			main(int argc, char **argv)
{
  sfRenderWindow	*window;
  SOCKET		sock;
  t_parse		*parse;
  t_ply			*ply;
  t_var			*var;

  if (argc == 3)
    {
      sock = start_connection(argv);
      if ((parse = get_parse(sock)) == NULL)
      	return (84);
      var = init_var();
      ply = init_ply(sock, parse);
      init_fire(ply);
      init_texture(ply);
      main_core(var, parse, ply);
      free_all(ply);
      return (0);
    }
  printf("USAGE : %s adresse_ip pseudo\n", argv[0]);
  return (84);
}
