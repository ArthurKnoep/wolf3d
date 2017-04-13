/*
** read_xpm.c for read in /home/arthur/test_xpm
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Dec 26 19:30:09 2016 Arthur Knoepflin
** Last update Tue Dec 27 16:37:04 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "wolf.h"

void		fill_one_line(t_frame *img, t_data *data, int i, char **texture)
{
  int		j;
  char		*buffer;
  sfColor	tmp;

  j = 0;
  while (j < data->width)
    {
      tmp = search_color(texture[i] + j * data->n_char_cl, data, texture);
      my_put_pixel(img, j, i - (data->n_color + 1), tmp);
      j += 1;
    }
}

void	read_xpm(t_frame *img, t_data *data, char **texture)
{
  int	i;
  int	j;

  i = data->n_color + 1;
  j = 0;
  while (i < data->n_color + data->height + 1)
    {
      fill_one_line(img, data, i, texture);
      i += 1;
      j += 1;
    }
}
