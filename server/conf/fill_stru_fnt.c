/*
** fill_stru_fnt.c for fill_stru_fnt$ in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 11:48:28 2016 Arthur Knoepflin
** Last update Thu Dec 22 13:26:33 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "server.h"
#include "my.h"

static int	len_sec_opt(char *opt)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (opt[i] && opt[i] != '=' && opt[i] != '\n')
    i += 1;
  while (opt[i] && opt[i] != '\n')
    {
      i += 1;
      count += 1;
    }
  return (count - 1);
}

void	fill_name(t_conf *conf, char *opt)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (opt[i] && opt[i] != '=')
    i += 1;
  if (opt[i] == '=')
    {
      conf->name = malloc(sizeof(char) * (len_sec_opt(opt) + 1));
      i += 1;
      j = 0;
      while (opt[i])
	{
	  conf->name[j] = opt[i];
	  i += 1;
	  j += 1;
	}
      conf->name[j] = '\0';
    }
}

void	fill_port(t_conf *conf, char *opt)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  j = 0;
  while (opt[i] && opt[i] != '=')
    i += 1;
  if (opt[i] == '=')
    {
      tmp = malloc(sizeof(char) * (len_sec_opt(opt) + 1));
      i += 1;
      j = 0;
      while (opt[i])
	{
	  tmp[j] = opt[i];
	  i += 1;
	  j += 1;
	}
      tmp[j] = '\0';
      conf->port = my_getnbr(tmp);
      free(tmp);
    }
}

void	fill_max_ply(t_conf *conf, char *opt)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  j = 0;
  while (opt[i] && opt[i] != '=')
    i += 1;
  if (opt[i] == '=')
    {
      tmp = malloc(sizeof(char) * (len_sec_opt(opt) + 1));
      i += 1;
      j = 0;
      while (opt[i])
	{
	  tmp[j] = opt[i];
	  i += 1;
	  j += 1;
	}
      tmp[j] = '\0';
      conf->max_player = my_getnbr(tmp);
      free(tmp);
    }
}

void	fill_map(t_conf *conf, char *opt)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (opt[i] && opt[i] != '=')
    i += 1;
  if (opt[i] == '=')
    {
      conf->map = malloc(sizeof(char) * (len_sec_opt(opt) + 1));
      i += 1;
      j = 0;
      while (opt[i])
	{
	  conf->map[j] = opt[i];
	  i += 1;
	  j += 1;
	}
      conf->map[j] = '\0';
    }
}
