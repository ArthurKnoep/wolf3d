/*
** init_connection.c for init_connection in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 14:17:44 2016 Arthur Knoepflin
** Last update Thu Dec 22 15:06:30 2016 Arthur Knoepflin
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "server.h"

int		init_connection(t_conf *conf)
{
  SOCKET	sock;
  SOCKADDR_IN	sin;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
      perror("socket ");
      exit(84);
    }
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  sin.sin_port = htons(conf->port);
  sin.sin_family = AF_INET;
  while (bind(sock, (SOCKADDR *) &sin, sizeof(sin)) == SOCKET_ERROR)
    {
      conf->port += 1;
      sin.sin_port = htons(conf->port);
      if (conf->port > 65535)
	exit(84);
    }
  if (listen(sock, conf->max_player) == SOCKET_ERROR)
    {
      perror("listen ");
      exit(84);
    }
  return (sock);
}

