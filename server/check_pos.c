/*
** check_pos.c for check_pos.c in /home/arthur/wolf3d_5/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Jan  2 21:58:23 2017 Arthur Knoepflin
** Last update Fri Jan  6 14:09:20 2017 
*/

#include "server.h"

void	check_pos(t_client *clients, t_nb_cli *cli)
{
  int	i;

  i = 0;
  while (i < cli->actual)
    {
      if (clients[i].x < 0 || clients[i].y < 0 ||
	  clients[i].x > cli->conf->parse->sizemap.y ||
	  clients[i].y > cli->conf->parse->sizemap.x ||
	  cli->conf->parse->data[(int) clients[i].y][(int) clients[i].x] != 0 &&
	  (clients[i].x != 0 && clients[i].y != 0))
	clients[i].life = 0;
      i += 1;
    }
}
