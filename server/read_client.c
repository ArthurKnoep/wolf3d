/*
** read_client.c for read_client in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 16:21:13 2016 Arthur Knoepflin
** Last update Thu Dec 22 17:41:52 2016 Arthur Knoepflin
*/

#include <stdio.h>
#include "server.h"
#include "my.h"

int	read_client(SOCKET sock, char *buffer)
{
  int	n;

  n = 0;
  if ((n  = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0)
    {
      perror("receive ");
      n = 0;
    }
  buffer[n] = 0;
  return (n);
}

int	write_client(SOCKET sock, char *buffer)
{
  if (send(sock, buffer, my_strlen(buffer), 0) < 0)
    {
      perror("send ");
      return (0);
    }
  return (1);
}
