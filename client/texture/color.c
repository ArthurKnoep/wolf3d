/*
** color.c for color.c in /home/arthur/test_xpm
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Dec 27 11:40:18 2016 Arthur Knoepflin
** Last update Fri Jan  6 16:49:51 2017 
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <string.h>
#include "wolf.h"
#include "my.h"

static sfColor	case_none()
{
  sfColor	ret;

  ret.r = 255;
  ret.g = 255;
  ret.b = 255;
  ret.a = 0;
  return (ret);
}

static sfColor	extract_color(char *str, t_data *data)
{
  int		j;
  sfColor	ret;
  char		*tmp;

  j = 0;
  tmp = malloc(sizeof(char) * 3);
  while (str[j] && str[j] != 'c')
    j += 1;
  j += 3;
  if (strcmp(str + (j - 1), "None") == 0)
    return (case_none());
  tmp = my_strncpy(tmp, str + j, 2);
  ret.r = my_getnbr_base(tmp, "0123456789ABCDEF");
  tmp = my_strncpy(tmp, str + 2 + j, 2);
  ret.g = my_getnbr_base(tmp, "0123456789ABCDEF");
  tmp = my_strncpy(tmp, str + 4 + j, 2);
  ret.b = my_getnbr_base(tmp, "0123456789ABCDEF");
  ret.a = 255;
  free(tmp);
  return (ret);
}

sfColor	search_color(char *meta, t_data *data, char **texture)
{
  sfColor tmp;
  int	i;

  i = 1;
  while (i < data->n_color + 1)
    {
      if (my_strncmp(texture[i], meta, data->n_char_cl) == 0)
	return (extract_color(texture[i] + data->n_char_cl, data));
      i += 1;
    }
  tmp.r = 0;
  tmp.g = 0;
  tmp.b = 0;
  tmp.a = 0;
  return (tmp);
}

sfColor		get_color(int x, int y, t_frame *texture)
{
  sfColor	ret;

  if (x >= 0 && y >= 0 && x < texture->height && y < texture->width)
    {
      ret.r = texture->pixels[(x * texture->width + y) * 4];
      ret.g = texture->pixels[(x * texture->width + y) * 4 + 1];
      ret.b = texture->pixels[(x * texture->width + y) * 4 + 2];
      ret.a = texture->pixels[(x * texture->width + y) * 4 + 3];
    }
  else
    return (sfRed);
  return (ret);
}
