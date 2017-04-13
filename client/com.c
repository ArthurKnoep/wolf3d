/*
** com.c for com in /home/arthur/wolf3d_3/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Dec 23 13:15:28 2016 Arthur Knoepflin
** Last update Fri Dec 23 13:56:11 2016 Arthur Knoepflin
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "wolf.h"

int	read_server(SOCKET sock, char *buffer)
{
  int	n;

  n = 0;
  if ((n = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0)
    {
      perror("receive ");
      exit(84);
    }
  buffer[n] = '\0';
  return (n);
}

void	write_server(SOCKET sock, char *buffer)
{
  if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
      perror("send ");
      exit(84);
    }
}
