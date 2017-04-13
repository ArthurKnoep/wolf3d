/*
** main.c for server in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 09:59:19 2016 Arthur Knoepflin
** Last update Mon Jan  2 15:34:14 2017 Arthur Knoepflin
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

void	free_all(t_conf *conf)
{
  free(conf->name);
  free(conf->map);
  free(conf);
}

void	init_client(fd_set *rdfs, t_nb_cli *n_cli, SOCKET sock, t_client *clients)
{
  int	i;

  i = 0;
  FD_ZERO(rdfs);
  FD_SET(STDIN_FILENO, rdfs);
  FD_SET(sock, rdfs);
  while (i < n_cli->actual)
    {
      FD_SET(clients[i].sock, rdfs);
      i += 1;
    }
  if (select(n_cli->max + 1, rdfs, NULL, NULL, NULL) == -1)
    {
      perror("select ");
      exit(84);
    }
}

static void	core(t_conf *conf, t_client *clients, SOCKET sock, t_nb_cli *n_cli)
{
  int		i;
  int		stop;
  fd_set	rdfs;

  while (1)
    {
      init_client(&rdfs, n_cli, sock, clients);
      if (FD_ISSET(STDIN_FILENO, &rdfs))
	break ;
      else if (FD_ISSET(sock, &rdfs))
	new_client(clients, n_cli, &rdfs, sock);
      else
	client_talk(clients, n_cli, &rdfs, conf);
    }
  printf("Fermeture du serveur\n");
  clear_clients(clients, n_cli->actual);
  end_connection(sock);
}

int		main(void)
{
  t_conf	*conf;
  t_client	*clients;
  t_nb_cli	nb_client;
  SOCKET	sock;

  conf = get_conf();
  conf->parse = get_parse(conf->map);
  sock = init_connection(conf);
  clients = malloc(sizeof(*clients) * conf->max_player);
  nb_client.max = sock;
  nb_client.actual = 0;
  nb_client.max_int = conf->max_player;
  printf("Initialisation terminé\nLe serveur \"%s\" utilise le port %d\n",
  	 conf->name, conf->port);
  core(conf, clients, sock, &nb_client);
  free_all(conf);
  free(clients);
  return (0);
}
