/*
** read_file.c for read_file in /home/arthur/delivery/MUL/wireframe
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Nov 21 16:35:32 2016 Arthur Knoepflin
** Last update Sun Jan  1 14:54:03 2017 Arthur Knoepflin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"
#include "my.h"

static char	*my_strcat_c(char *str1, char *str2, int size)
{
  int		i;
  int		j;
  char		*ret;

  if (str1 == NULL)
    str1 = my_strdup("");
  ret = malloc(sizeof(*ret) * (my_strlen(str1) + size + 1));
  ret[my_strlen(str1) + size] = '\0';
  i = 0;
  while (str1[i])
    {
      ret[i] = str1[i];
      i += 1;
    }
  j = 0;
  while (j < size)
    {
      ret[i] = str2[j];
      i += 1;
      j += 1;
    }
  free(str1);
  return (ret);
}

char		*read_f(char *src)
{
  int		fd;
  struct stat	stati;
  char		*ret;

  ret = NULL;
  if ((fd = open(src, O_RDONLY)) == -1)
    return (NULL);
  if (stat(src, &stati) == -1)
    return (NULL);
  ret = malloc(sizeof(*ret) * (stati.st_size + 1));
  ret[stati.st_size] = '\0';
  read(fd, ret, stati.st_size);
  return (ret);
}
