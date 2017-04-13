/*
** read_file.c for read_file in /home/arthur/delivery/MUL/wireframe
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Nov 21 16:35:32 2016 Arthur Knoepflin
** Last update Fri Dec 23 14:00:02 2016 Arthur Knoepflin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "wolf.h"
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

char	*read_file(SOCKET sock)
{
  int	fd;
  int	size;
  char	buffer[BUF_SIZE];
  char	*ret;

  ret = NULL;
  write_server(sock, "<MAP>");
  size = read_server(sock, buffer);
  ret = my_strcat_c(ret, buffer, size);
  return (ret);
}
