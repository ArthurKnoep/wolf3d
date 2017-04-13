/*
** connection.c for connection in /home/arthur/wolf3d_3/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Dec 23 12:59:25 2016 Arthur Knoepflin
** Last update Mon Jan  2 15:07:29 2017 Arthur Knoepflin
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include "wolf.h"

int			init_connection(char *address)
{
  SOCKET		sock;
  SOCKADDR_IN		sin;
  struct hostent	*hostinfo;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
      perror("socket ");
      exit(84);
    }
  hostinfo = gethostbyname(address);
  if (hostinfo == NULL)
    {
      printf("Impossible de trouver %s\n", address);
      exit(84);
    }
  sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr;
  sin.sin_port = htons(PORT);
  sin.sin_family = AF_INET;
  if (connect(sock, (SOCKADDR *)&sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
      perror("connect ");
      exit(84);
    }
  return (sock);
}

SOCKET		start_connection(char **argv)
{
  char		buf[BUF_SIZE];
  SOCKET	sock;
  int		size;

  sock = init_connection(argv[1]);
  write_server(sock, argv[2]);
  size = read_server(sock, buf);
  if (my_strncmp(buf, "<OK>", size) != 0)
    return (84);
  return (sock);
}
