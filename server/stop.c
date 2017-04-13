/*
** stop.c for stop in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 16:57:41 2016 Arthur Knoepflin
** Last update Thu Dec 22 17:33:02 2016 Arthur Knoepflin
*/

#include <string.h>
#include "server.h"

void	end_connection(SOCKET sock)
{
  closesocket(sock);
}

void	clear_clients(t_client *clients, int actual)
{
  int	i;

  i = 0;
  while (i < actual)
    {
      closesocket(clients[i].sock);
      i += 1;
    }
}

void	remove_client(t_client *clients, int to_remove, t_nb_cli *cli)
{
  memmove(clients + to_remove, clients + to_remove + 1,
	  (cli->actual - to_remove - 1) * sizeof(t_client));
  cli->actual -= 1;
}
