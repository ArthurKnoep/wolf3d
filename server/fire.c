/*
** fire.c for fire in /home/arthur/wolf3d_5/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sat Dec 31 14:18:51 2016 Arthur Knoepflin
** Last update Tue Jan 10 22:50:55 2017 
*/

#include <stdlib.h>
#include "server.h"
#include "my.h"

void	rep_client_weap(t_client *clients, int i, t_nb_cli *cli, t_weap weap)
{
  clients[i].time = get_tick();
  if (fire(clients, i, cli, weap))
    write_client(clients[i].sock, "<OK>");
  else
    write_client(clients[i].sock, "<NOPE>");
}

void	randomize(t_client *clients, int index, t_weap weap)
{
  float	rand1;

  if (weap.visor == 1)
    {
      rand1 = rand() / (double) RAND_MAX;
      if (rand() % 2 == 0)
	clients[index].angle += (rand1 * 2.0);
      else
	clients[index].angle -= (rand1 * 2.0);
    }
}

int	hit(t_weap weap, t_client *clients, int i, int *ret)
{
  if (weap.weap == 1)
    clients[i].life -= 1;
  else if (weap.weap == 2)
    clients[i].life = 0;
  *ret = 1;
}

int		fire(t_client *clients, int index, t_nb_cli *cli, t_weap weap)
{
  int		ret;
  int		i;
  float		angle;
  t_parse	*parse;

  i = 0;
  ret = 0;
  randomize(clients, index, weap);
  while (i < cli->actual)
    {
      if (i != index)
	{
	  angle = angle_enn(clients[index], clients[i]);
	  if (angle >= -1.00 && angle <= 1.00 && clients[i].life > 0)
	    if (is_visible(clients[index], clients[i], cli->conf->parse))
	      hit(weap, clients, i, &ret);
	}
      i += 1;
    }
  return (ret);
}

void	fill_weapon(char *msg, t_weap *weap)
{
  char	*buf;

  msg = msg + my_strlen(FIRE_S);
  buf = malloc(sizeof(char) * BUF_SIZE);
  buf = my_strncpy(buf, msg, len_separator(msg, 0));
  weap->weap = atoi(buf);
  buf = my_strncpy(buf, msg + total_len_sep(msg, 1), len_separator(msg, 1));
  weap->visor = atoi(buf);
  free(buf);
}
