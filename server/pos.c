/*
** pos.c for pos.c in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 21:54:58 2016 Arthur Knoepflin
** Last update Sat Dec 31 14:05:28 2016 Arthur Knoepflin
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "my.h"

char	*my_strcat_s(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*ret;

  ret = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
  ret[my_strlen(str1) + my_strlen(str2)] = '\0';
  i = 0;
  while (str1[i])
    {
      ret[i] = str1[i];
      i += 1;
    }
  j = 0;
  while (str2[j])
    {
      ret[i] = str2[j];
      i += 1;
      j += 1;
    }
  free(str1);
  return (ret);
}

char	*get_all_pos(t_client *clients, int j, t_nb_cli *cli)
{
  int	i;
  int	first;
  char	tmp[BUF_SIZE];
  char	*ret;

  i = 0;
  first = 0;
  ret = my_strdup("");
  while (i < cli->actual)
    {
      if (i != j)
	{
	  if (first == 0 && first++)
	    sprintf(tmp, "%s;%.3f;%.3f;%.3f;%d", clients[i].name,
		    clients[i].x, clients[i].y, clients[i].angle, clients[i].life);
	  else
	    sprintf(tmp, "\n%s;%.3f;%.3f;%.3f;%d", clients[i].name,
		    clients[i].x, clients[i].y, clients[i].angle, clients[i].life);
	  ret = my_strcat_s(ret, tmp);
	}
      i += 1;
    }
  return (ret);
}

int	len_separator(char *msg, int index)
{
  int	count;
  int	i;

  i = 0;
  count = 0;
  while (msg[i] && count < index)
    {
      if (msg[i] == ';')
	count += 1;
      i += 1;
    }
  count = 0;
  while (msg[i] && msg [i] != ';')
    {
      count += 1;
      i += 1;
    }
  return (count);
}

int	total_len_sep(char *msg, int index)
{
  int	total;
  int	i;

  total = 0;
  i = 0;
  while (i < index)
    {
      total += len_separator(msg, i) + 1;
      i += 1;
    }
  return (total);
}

t_pos	get_pos(char *msg)
{
  char	tmp[BUF_SIZE];
  t_pos	ret;

  my_strncpy(tmp, msg, len_separator(msg, 0));
  tmp[len_separator(msg, 0)] = '\0';
  ret.x = atof(tmp);
  my_strncpy(tmp, msg + total_len_sep(msg, 1), len_separator(msg, 1));
  tmp[len_separator(msg, 1)] = '\0';
  ret.y = atof(tmp);
  my_strncpy(tmp, msg + total_len_sep(msg, 2), len_separator(msg, 2));
  tmp[len_separator(msg, 2)] = '\0';
  ret.angle = atof(tmp);
  return (ret);
}
