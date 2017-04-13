/*
** kill_all.c for kill_all in /home/arthur/wolf3d_5/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Jan  2 15:46:45 2017 Arthur Knoepflin
** Last update Mon Jan  2 15:56:06 2017 Arthur Knoepflin
*/

#include "server.h"

void	kill_all(t_client *clients, int index, t_nb_cli *cli)
{
  int	i;

  i = 0;
  while (i < cli->actual)
    {
      if (i != index)
	clients[i].life = 0;
      i += 1;
    }
}
