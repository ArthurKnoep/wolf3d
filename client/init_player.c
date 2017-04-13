/*
** init_player.c for init in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Dec 19 10:18:14 2016 Arthur Knoepflin
** Last update Fri Jan 13 16:26:43 2017 
*/

#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fire.xpm"
#include "hud.xpm"
#include "go.xpm"
#include "enn_2.xpm"
#include "redbrick.xpm"
#include "bluestone.xpm"
#include "eagle.xpm"
#include "greystone.xpm"
#include "mossy.xpm"
#include "purplestone.xpm"
#include "colorstone.xpm"
#include "wood.xpm"
#include "dead.xpm"
#include "sky_2.xpm"
#include "viseur.xpm"
#include "awp.xpm"
#include "awp_fire.xpm"
#include "wolf.h"

t_var	*init_var()
{
  t_var	*var;

  if ((var = malloc(sizeof(*var))) == NULL)
    return (NULL);
  if ((var->win = create_window(HEIGHT, WIDTH, "Wolf3D")) == NULL)
    return (NULL);
  var->nb_frame = 0;
  var->mouse.x = WIDTH / 2;
  var->mouse.y = HEIGHT / 2;
  sfMouse_setPosition(var->mouse, (sfWindow *) var->win);
  return (var);
}

t_ply	*init_ply(SOCKET sock, t_parse *parse)
{
  t_ply	*ply;

  if ((ply = malloc(sizeof(*ply))) == NULL)
    return (NULL);
  srand(time(NULL));
  ply->pos.x = rand() % parse->sizemap.y;
  ply->pos.y = rand() % parse->sizemap.x;
  while (parse->data[(int) ply->pos.y][(int) ply->pos.x] != 0)
    {
      ply->pos.x = rand() % parse->sizemap.y;
      ply->pos.y = rand() % parse->sizemap.x;
    }
  ply->zoom = 1;
  ply->speed_mouse = 10.0;
  ply->pos.x += 0.5;
  ply->pos.y += 0.5;
  ply->angle = 0.0;
  ply->fov = FOV;
  ply->sock = sock;
  ply->nb_player = 0;
  ply->life = 2;
  return (ply);
}

void	init_fire_2(t_ply *ply)
{
  if ((ply->fire->awp_hit =
       sfMusic_createFromFile("sound/awp_hit.ogg")) == NULL)
    {
      perror("Sound ");
      exit (84);
    }
  if ((ply->fire->zoom =
       sfMusic_createFromFile("sound/zoom.ogg")) == NULL)
    {
      perror("Sound ");
      exit (84);
    }
}

void	init_fire(t_ply *ply)
{
  if ((ply->fire = malloc(sizeof(*(ply->fire)))) == NULL)
    return ;
  if ((ply->fire->sound = sfMusic_createFromFile("sound/fire.ogg")) == NULL)
    {
      perror("Sound ");
      exit (84);
    }
  if ((ply->fire->hit_sound =
       sfMusic_createFromFile("sound/fire_hit.ogg")) == NULL)
    {
      perror("Sound ");
      exit (84);
    }
  if ((ply->fire->awp = sfMusic_createFromFile("sound/awp.ogg")) == NULL)
    {
      perror("Sound ");
      exit (84);
    }
  ply->fire->time = 0;
  ply->fire->act_weap = 1;
  ply->fire->zoom_time = 0;
  init_fire_2(ply);
}

void	init_texture(t_ply *ply)
{
  ply->text[0] = load_texture(redbrick_xpm);
  ply->text[1] = load_texture(eagle_xpm);
  ply->text[2] = load_texture(bluestone_xpm);
  ply->text[3] = load_texture(purplestone_xpm);
  ply->text[4] = load_texture(greystone_xpm);
  ply->text[5] = load_texture(mossy_xpm);
  ply->text[6] = load_texture(wood_xpm);
  ply->text[7] = load_texture(colorstone_xpm);
  ply->text_enn = load_texture(enn_xpm);
  ply->enn_dead = load_texture(dead_xpm);
  ply->hud = load_texture(hud_xpm);
  ply->fire_hud = load_texture(fire_xpm);
  ply->awp = load_texture(awp_xpm);
  ply->dot_red = load_texture(viseur_xpm);
  ply->awp_hud = load_texture(awp_fire_xpm);
  ply->go = load_texture(go_xpm);
  ply->sky = load_texture(sky_xpm);
}
