/*
** fill_stru.c for fill_stru in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 11:14:56 2016 Arthur Knoepflin
** Last update Thu Dec 22 13:03:42 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "server.h"
#include "my.h"

static int	get_len_opt(char *opt)
{
  int		i;

  i = 0;
  while (opt[i] && opt[i] != '=' && opt[i] != '\n')
    i += 1;
  return (i);
}

static char	*get_firstval(char *opt)
{
  char		*tmp;
  int		i;

  tmp = malloc(sizeof(char) * (get_len_opt(opt) + 1));
  tmp[get_len_opt(opt)] = '\0';
  i = 0;
  while (i < get_len_opt(opt))
    {
      tmp[i] = opt[i];
      i += 1;
    }
  return (tmp);
}

int	nb_opt(char *opt)
{
  char	*tmp;

  tmp = get_firstval(opt);
  if (my_strcmp(tmp, NAME) == 0)
    {
      free(tmp);
      return (0);
    }
  if (my_strcmp(tmp, PORT) == 0)
    {
      free(tmp);
      return (1);
    }
  if (my_strcmp(tmp, MAX_PLAYER) == 0)
    {
      free(tmp);
      return (2);
    }
  if (my_strcmp(tmp, MAP) == 0)
    {
      free(tmp);
      return (3);
    }
  free(tmp);
  return (-1);
}

void	fill_stru(t_conf *conf, char *opt)
{
  int	index_opt;
  void	(*fill_stru_fnt[4])(t_conf *, char *);

  fill_stru_fnt[0] = &fill_name;
  fill_stru_fnt[1] = &fill_port;
  fill_stru_fnt[2] = &fill_max_ply;
  fill_stru_fnt[3] = &fill_map;
  index_opt = nb_opt(opt);
  if (index_opt != -1)
    {
      fill_stru_fnt[index_opt](conf, opt);
    }
}
