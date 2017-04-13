/*
** conf.c for conf in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 10:04:15 2016 Arthur Knoepflin
** Last update Thu Dec 22 15:19:02 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "server.h"

void	free_parse_conf(char **parse)
{
  int	i;

  i = 0;
  while (parse[i])
    {
      free(parse[i]);
      i += 1;
    }
  free(parse);
}

int	is_etx(char c)
{
  if (c == '\n' || c == '\0')
    return (1);
  return (0);
}

void	get_opt(char **opt, char *file)
{
  int	i;
  int	j;

  i = 0;
  while (i < nb_line(file))
    {
      opt[i] = malloc(sizeof(char) * (len_opt(file, i) + 1));
      opt[i][len_opt(file, i)] = '\0';
      j = 0;
      while (j < len_opt(file, i))
	{
	  opt[i][j] = file[get_index(file, i) + j];
	  j += 1;
	}
      i += 1;
    }
}

char	**parse_conf()
{
  char	*file;
  char	**opt;

  file = read_file();
  opt = malloc(sizeof(char *) * (nb_line(file) + 1));
  opt[nb_line(file)] = NULL;
  get_opt(opt, file);
  free(file);
  return (opt);
}

t_conf		*get_conf()
{
  int		i;
  char		**conf;
  t_conf	*conf_stru;

  conf = parse_conf();
  conf_stru = malloc(sizeof(*conf_stru));
  i = 0;
  while (conf[i])
    {
      if (conf[i][0] != '#')
	{
	  fill_stru(conf_stru, conf[i]);
	}
      i += 1;
    }
  free_parse_conf(conf);
  check_error(conf_stru);
  return (conf_stru);
}
