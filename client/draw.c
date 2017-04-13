/*
** draw.c for draw in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Dec 20 21:32:30 2016 Arthur Knoepflin
** Last update Tue Jan 10 10:52:56 2017 
*/

#include <stdlib.h>
#include "wolf.h"

static void	draw_texture(t_frame *frame,
			     t_ply *ply,
			     sfVector2i pos,
			     t_raycast rc)
{
  sfVector2i	inc;
  sfColor	color;

  inc.x = ((float) (pos.x - (HEIGHT - rc.height_wall) / 2) / rc.height_wall) *
    (ply->text[rc.type_wall]->height - 1);
  inc.y = ply->text[rc.type_wall]->width * rc.offset;
  color = get_color(inc.x, inc.y, ply->text[rc.type_wall]);
  if (rc.side == 0)
    color.a -= 50;
  my_put_pixel(frame, WIDTH - pos.y, pos.x, color);
}

static void	draw_line_w(t_frame *frame, t_raycast rc, int i, t_ply *ply)
{
  sfVector2i	pos_px;
  float		ratio;
  sfColor	ground;

  pos_px.y = i;
  pos_px.x = 0;
  ratio = 200.0 / (float) (HEIGHT / 2);
  ground = ground_color();
  while (pos_px.x < HEIGHT)
    {
      if (pos_px.x < (HEIGHT / 2 - rc.height_wall / 2))
	draw_sky(frame, ply, pos_px);
      else if (pos_px.x > (HEIGHT / 2 + rc.height_wall / 2))
	{
	  ground.a = (int) ((float) ((pos_px.x - ((HEIGHT / 2)))) * ratio);
	  my_put_pixel(frame, WIDTH - pos_px.y, pos_px.x, ground);
	}
      else
      	draw_texture(frame, ply, pos_px, rc);
      pos_px.x += 1;
    }
}

static void	draw_wall(t_frame *frame, t_parse *in, t_ply *ply)
{
  int		i;
  t_raycast	rc;
  float		fov;
  int		j;
  int		height_wall;

  fov = ((float) ply->fov / WIDTH);
  i = 0;
  while (i < WIDTH)
    {
      ply->i = i;
      rc = raycast_stru(ply, (i * fov) + ply->angle - ply->fov / 2,
			in->data, in->sizemap);
      draw_line_w(frame, rc, i, ply);
      i += 1;
    }
}

void	draw(t_frame *frame, t_parse *parse, t_ply *ply, t_var *var)
{
  if (ply->life > 0)
    {
      ply->fov /= ply->zoom;
      get_nb_player(ply, var->nb_frame);
      send_pos(ply, var->nb_frame);
      draw_wall(frame, parse, ply);
      if (var->nb_frame % FRAME_RATE == 0)
      	ply->pos_ply = get_pos(ply, var->nb_frame);
      draw_skin(frame, ply, parse);
      draw_hud(frame, ply);
      minimap(frame, parse, ply);
      draw_all_player(frame, parse, ply->pos_ply, ply);
      draw_all_view(frame, parse, ply->pos_ply, ply);
      fire(ply);
      ply->fov = FOV;
    }
  else
    {
      send_pos(ply, var->nb_frame);
      game_over(frame, ply, parse);
    }
  var->nb_frame += 1;
}
