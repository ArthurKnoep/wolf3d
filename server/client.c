/*
** new_client.c for new_client in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 15:56:42 2016 Arthur Knoepflin
** Last update Mon Jan  2 15:09:18 2017 Arthur Knoepflin
*/

#include <stdio.h>
#include "server.h"
#include "my.h"

static int	limit_player(t_nb_cli *cli, SOCKET csock)
{
  if (cli->actual >= cli->max_int)
    {
      printf("Trop de joueur connecté\n");
      close(csock);
      return (1);
    }
  else
    printf("Nouveaux client : ");
  return (0);
}

static void	init_client(t_client *c, SOCKET csock)
{
  c->sock = csock;
  c->x = 0;
  c->y = 0;
  c->angle = 0;
  c->life = 2;
  c->time = 0;
}

int		new_client(t_client *clients,
			   t_nb_cli *cli,
			   fd_set *rdfs,
			   SOCKET sock)
{
  SOCKADDR_IN	csin;
  socklen_t	sinsize;
  SOCKET	csock;
  t_client	c;
  char		buffer[BUF_SIZE];

  sinsize = sizeof(csin);
  if ((csock = accept(sock, (SOCKADDR *)&csin, &sinsize)) == SOCKET_ERROR)
    {
      perror("");
      return (0);
    }
  if (limit_player(cli, csock))
    return (0);
  if (read_client(csock, buffer) == -1)
    return (0);
  write_client(csock, "<OK>");
  cli->max = csock > cli->max ? csock : cli->max;
  FD_SET(csock, rdfs);
  my_strncpy(c.name, buffer, BUF_SIZE - 1);
  init_client(&c, csock);
  printf("%s\n", c.name);
  clients[cli->actual] = c;
  cli->actual += 1;
}

void		client_talk(t_client *clients,
			    t_nb_cli *cli,
			    fd_set *rdfs,
			    t_conf *conf)
{
  int		i;
  int		c;
  t_client	client;
  char		buffer[BUF_SIZE];

  i = 0;
  while (i < cli->actual)
    {
      if (FD_ISSET(clients[i].sock, rdfs))
	{
	  client = clients[i];
	  c = read_client(client.sock, buffer);
	  if (c == 0)
	    client_disconnect(clients, cli, i);
	  else
	    {
	      cli->conf = conf;
	      client_treat_msg(clients, i, buffer, cli);
	    }
	}
      i += 1;
    }
}

void	client_disconnect(t_client *clients, t_nb_cli *cli, int i)
{
  printf("%s est deconneté\n", clients[i].name);
  closesocket(clients[i].sock);
  remove_client(clients, i, cli);
}
