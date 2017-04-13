/*
** fill_stru.c for fill_stru in /home/arthur/test_xpm
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Dec 26 18:41:19 2016 Arthur Knoepflin
** Last update Tue Dec 27 16:36:21 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "wolf.h"
#include "my.h"

t_data		*fill_stru(char **texture)
{
  t_data	*ret;
  char		**info;

  if ((ret = malloc(sizeof(*ret))) == NULL)
    return (NULL);
  info = my_str_to_wordtab(texture[0]);
  ret->width = my_getnbr(info[0]);
  ret->height = my_getnbr(info[1]);
  ret->n_color = my_getnbr(info[2]);
  ret->n_char_cl = my_getnbr(info[3]);
  return (ret);
}
