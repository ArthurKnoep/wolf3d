/*
** my_strncmp.c for my_strncmp in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 18:50:36 2016 Arthur Knoepflin
** Last update Mon Jan  2 10:38:27 2017 Arthur Knoepflin
*/

#include <stdlib.h>

int	my_strncmp(char *s1, char *s2, int index)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && i < index)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}

int	size_nb(int nb)
{
  int	size;

  size = 0;
  if (nb == 0)
    return (1);
  while (nb != 0)
    {
      nb = nb / 10;
      size += 1;
    }
  return (size);
}

char	*int_to_char(int nb)
{
  int	i;
  char	*ret;

  ret = malloc(sizeof(*ret) * (size_nb(nb) + 1));
  ret[size_nb(nb)] = '\0';
  if (i == 0)
    ret[0] = '0';
  i = size_nb(nb) - 1;
  while (i >= 0)
    {
      ret[i] = (nb % 10) + '0';
      nb /= 10;
      i -= 1;
    }
  return (ret);
}
