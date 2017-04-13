/*
** parse.c for parse in /home/arthur/delivery/MUL/wolf
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Nov 21 16:25:44 2016 Arthur Knoepflin
** Last update Sun Jan  1 14:56:31 2017 Arthur Knoepflin
*/

#include <stdlib.h>
#include "server.h"
#include "my.h"

int	get_width_len(char *file, int line)
{
  int	i;

  i = 0;
  while (file[i] && line > 0)
    {
      if (file[i] == '\n')
	line -= 1;
      i += 1;
    }
  return (i);
}

void	fill_array(t_parse *ret, int i, char *file)
{
  int	j;
  int	neg;
  int	x;
  int	tmp;

  j = 0;
  x = 0;
  while (j < ret->width)
    {
      neg = 0;
      tmp = 0;
      while (file[ret->width_len + x] != '\n' &&
	     file[ret->width_len + x] != ',' &&
	     file[ret->width_len + x] != '\0')
	fill_array_2(file[ret->width_len + x], &x, &neg, &tmp);
      if (neg == 1)
	tmp *= -1;
      ret->data[i][j] = tmp;
      x += 1;
      j += 1;
    }
}

t_parse		*get_parse(char *src)
{
  char		*file;
  t_parse	*ret;
  int		i;

  if ((file = read_f(src)) == NULL)
    return (NULL);
  ret = malloc(sizeof(*ret));
  ret->width = get_width(file);
  ret->height = get_height(file);
  ret->data = malloc(sizeof(int *) * ret->height);
  i = 0;
  while (i < ret->height)
    {
      ret->data[i] = malloc(sizeof(int **) * ret->width);
      ret->width_len = get_width_len(file, i);
      fill_array(ret, i, file);
      i += 1;
    }
  ret->sizemap.x = ret->height;
  ret->sizemap.y = ret->width;
  free(file);
  return (ret);
}
