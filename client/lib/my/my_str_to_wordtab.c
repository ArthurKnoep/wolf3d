/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/arthur/delivery/CPool_Day08/
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Wed Oct 12 11:57:23 2016 Arthur Knoepflin
** Last update Tue Dec 27 15:03:07 2016 Arthur Knoepflin
*/
#include <stdlib.h>

int	is_alphanum(char c)
{
  if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
    return (1);
  return (0);
}

int	nb_len_par(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (!is_alphanum(str[i]))
    i += 1;
  while (str[i] != '\0')
    {
      if (is_alphanum(str[i]))
	{
  	  count += 1;
	  while (is_alphanum(str[i]) && str[i])
	    i += 1;
	}
      if (str[i] != '\0')
	i += 1;
    }
  return (count);
}

int	index_child(char *str, int index)
{
  int	i;
  int	count;

  i = 0;
  count = 1;
  while (!is_alphanum(str[i]))
    i += 1;
  while (str[i] != '\0' && count < index)
    {
      if (!is_alphanum(str[i]))
	{
	  count += 1;
	  while (!is_alphanum(str[i]))
	    i += 1;
	}
      i += 1;
    }
  if (i - 1 >= 0 && index != 1)
    return (i - 1);
  else if (index == 1)
    return (i);
  else
    return (0);
}

int	nb_len_child(char *str, int index)
{
  int	start;
  int	i;

  i = index_child(str, index);
  while (is_alphanum(str[i]))
    {
      i += 1;
    }
  return (i - index_child(str, index));
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	index;
  char	**tab;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (nb_len_par(str) + 1))) == NULL)
    return (NULL);
  tab[nb_len_par(str)] = NULL;
  while (i < nb_len_par(str))
    {
      tab[i] = malloc(sizeof(char) * (nb_len_child(str, i + 1) + 1));
      index = index_child(str, i + 1);
      j = 0;
      while (j < nb_len_child(str, i + 1))
        {
  	  tab[i][j] = str[index];
          j += 1;
  	  index += 1;
        }
      tab[i][j] = '\0';
      i += 1;
    }
  return (tab);
}
