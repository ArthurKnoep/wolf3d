/*
** check_error.c for check_error in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 15:11:22 2016 Arthur Knoepflin
** Last update Thu Dec 22 15:30:43 2016 Arthur Knoepflin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "server.h"

void		check_error(t_conf *conf)
{
  struct stat	stati;

  if (conf->port <= 0 || conf->port > 65535)
    {
      printf("Le port doit être strictement superieur à 0 et inferieur\
 ou égale à 6535\nPort actuel : %d\n", conf->port);
      free_all(conf);
      exit(84);
    }
  if (stat(conf->map, &stati) == -1)
    {
      perror("Map ");
      free_all(conf);
      exit(84);
    }
  if (!S_ISREG(stati.st_mode))
    {
      printf("La map doit être un fichier\n");
      free_all(conf);
      exit(84);
    }
}
