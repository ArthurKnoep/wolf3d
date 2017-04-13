/*
** read_file.c for read_file in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 10:05:53 2016 Arthur Knoepflin
** Last update Thu Dec 22 10:58:25 2016 Arthur Knoepflin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

int	len_opt(char *str, int index)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] && count < index)
    {
      if (is_etx(str[i]))
	count += 1;
      i += 1;
    }
  count = 0;
  while (str[i] && str[i] != '\n')
    {
      i += 1;
      count += 1;
    }
  return (count);
}

int	get_index(char *str, int index)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] && count < index)
    {
      if (is_etx(str[i]))
	count += 1;
      i += 1;
    }
  return (i);
}

int	nb_line(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (is_etx(str[i]))
	count += 1;
      i += 1;
    }
  return (count);
}

char		*read_file()
{
  char		*file;
  int		fd;
  struct stat	stati;

  if ((fd = open(CONF_F, O_RDONLY)) == -1)
    {
      perror(CONF_F);
      exit(84);
    }
  if (stat(CONF_F, &stati) == -1)
    {
      perror(CONF_F);
      exit(84);
    }
  file = malloc(sizeof(*file) * (stati.st_size + 1));
  file[stati.st_size] = '\0';
  read(fd, file, stati.st_size);
  return (file);
}
