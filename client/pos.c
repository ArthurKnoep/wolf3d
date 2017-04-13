/*
** pos.c for pos in /home/arthur/wolf3d_3/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Dec 23 15:44:50 2016 Arthur Knoepflin
** Last update Fri Jan  6 14:40:00 2017 
*/

#include <stdlib.h>
#include <stdio.h>
#include "wolf.h"
#include "my.h"

void	send_pos(t_ply *ply, int nb_frame)
{
  char	buffer[BUF_SIZE];

  if (nb_frame % FRAME_RATE == 0)
    {
      sprintf(buffer, "<SET_POS>%.3f;%.3f;%.3f",
	      ply->pos.x, ply->pos.y, ply->angle);
      write_server(ply->sock, buffer);
      read_server(ply->sock, buffer);
      ply->life = atoi(buffer);
    }
}

void	get_nb_player(t_ply *ply, int nb_frame)
{
  char	buffer[BUF_SIZE];

  if (nb_frame % FRAME_RATE == 0)
    {
      write_server(ply->sock, "<NB_PLY>");
      read_server(ply->sock, buffer);
      ply->nb_player = my_getnbr(buffer);
    }
}

int	get_pos_i(char *buf, int index)
{
  int	count;
  int	i;

  i = 0;
  count = 0;
  while (buf[i] && count < index)
    {
      if (buf[i] == '\n')
	count += 1;
      i += 1;
    }
  while (buf[i] != ';')
    i += 1;
  return (i + 1);
}

t_pos	get_pos_uni(char *buf, int index)
{
  t_pos	ret;
  int	i;
  int	j;
  char	tmp[BUF_SIZE];


  j = 0;
  i = get_pos_i(buf, index);
  ret.y = get_y_pos(buf, i);
  ret.x = get_x_pos(buf, i);
  ret.angle = get_angle_pos(buf, i);
  ret.life = get_life_pos(buf, i);
  return (ret);
}

t_pos	*get_pos(t_ply *ply, int nb_frame)
{
  char	buffer[BUF_SIZE];
  t_pos	*ret;
  int	i;

  if (nb_frame % FRAME_RATE == 0)
    {
      write_server(ply->sock, "<POS>");
      read_server(ply->sock, buffer);
      if (my_strncmp(buffer, "<NO_PLY>", my_strlen("<NO_PLY>")) != 0)
      	{
	  ret = malloc(sizeof(*ret) * (ply->nb_player));
	  i = 0;
	  while (i < ply->nb_player)
	    {
	      ret[i] = get_pos_uni(buffer, i);
	      i += 1;
	    }
	}
      else
	return (NULL);
    }
  return (ret);
}
