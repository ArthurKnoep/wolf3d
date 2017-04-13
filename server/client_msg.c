/*
** client_msg.c for client_msg in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 17:46:40 2016 Arthur Knoepflin
** Last update Tue Jan 10 22:48:12 2017 
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "server.h"
#include "my.h"

static char	*get_map(char *src)
{
  char		*file;
  int		fd;
  struct stat	stati;

  if ((fd = open(src, O_RDONLY)) == -1)
    {
      perror(src);
      exit(84);
    }
  if (stat(src, &stati) == -1)
    {
      perror(src);
      exit(84);
    }
  file = malloc(sizeof(*file) * (stati.st_size + 1));
  file[stati.st_size] = '\0';
  read(fd, file, stati.st_size);
  return (file);
}

static void	client_treat_4(t_client *clients, int i, char *msg, t_nb_cli *cli)
{
  if (my_strncmp(msg, KA_S, my_strlen(KA_S)) == 0)
    {
      kill_all(clients, i, cli);
      write_client(clients[i].sock, "<OK>");
    }
  check_pos(clients, cli);
}

static void	client_treat_3(t_client *clients, int i, char *msg, t_nb_cli *cli)
{
  t_weap	weap;

  if (my_strncmp(msg, FIRE_S, my_strlen(FIRE_S)) == 0)
    {
      fill_weapon(msg, &weap);
      if (weap.weap == 1 && clients[i].time < get_tick() - 490)
	rep_client_weap(clients, i, cli, weap);
      else if (weap.weap == 2 && clients[i].time < get_tick() - 980)
	rep_client_weap(clients, i, cli, weap);
      else
      	{
	  printf("%s is a cheater\n", clients[i].name);
      	  clients[i].life = 0;
      	  write_client(clients[i].sock, "<KO>");
      	}
    }
  if (my_strncmp(msg, RESP_S, my_strlen(RESP_S)) == 0)
    {
      clients[i].life = 2;
      write_client(clients[i].sock, "<OK>");
    }
  client_treat_4(clients, i, msg, cli);
}

static void	client_treat_2(t_client *clients, int i, char *msg, t_nb_cli *cli)
{
  char		*response;
  t_pos		pos;

  if (my_strncmp(msg, PLY_MAX_S, my_strlen(PLY_MAX_S)) == 0)
    {
      response = int_to_char(cli->max_int);
      write_client(clients[i].sock, response);
      free(response);
    }
  if (my_strncmp(msg, SET_POS_S, my_strlen(SET_POS_S)) == 0)
    {
      pos = get_pos(msg + my_strlen(SET_POS_S));
      clients[i].x = pos.x;
      clients[i].y = pos.y;
      clients[i].angle = pos.angle;
      response = int_to_char(clients[i].life);
      write_client(clients[i].sock, response);
    }
  client_treat_3(clients, i, msg, cli);
}

void	client_treat_msg(t_client *clients, int i, char *msg, t_nb_cli *cli)
{
  char	*response;

  if (my_strncmp(msg, MAP_S, my_strlen(MAP_S)) == 0)
    {
      response = get_map(cli->conf->map);
      write_client(clients[i].sock, response);
      free(response);
    }
  if (my_strncmp(msg, POS_S, my_strlen(POS_S)) == 0)
    {
      if (cli->actual > 1)
	response = get_all_pos(clients, i, cli);
      else
	response = my_strdup("<NO_PLY>");
      write_client(clients[i].sock, response);
      free(response);
    }
  if (my_strncmp(msg, NB_PLY_S, my_strlen(NB_PLY_S)) == 0)
    {
      response = int_to_char(cli->actual);
      write_client(clients[i].sock, response);
      free(response);
    }
  client_treat_2(clients, i, msg, cli);
}
