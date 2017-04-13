/*
** size_file.c for size_file.c in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Nov 21 20:33:56 2016 Arthur Knoepflin
** Last update Mon Dec 19 11:09:31 2016 Arthur Knoepflin
*/

#include "wolf.h"

int	get_width(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] && str[i] != '\n')
    {
      if (str[i] == ',')
	count += 1;
      i += 1;
    }
  return (count);
}

int	get_height(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	count += 1;
      i += 1;
    }
  return (count);
}
