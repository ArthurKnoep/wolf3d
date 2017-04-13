/*
** my_strstr.c for my_strstr in /home/arthur/delivery/CPool_Day06
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Mon Oct 10 11:01:01 2016 Arthur Knoepflin
** Last update Thu Oct 13 22:09:52 2016 Arthur Knoepflin
*/
#include <stdlib.h>

static int	my_strstr_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
      i = i + 1;
  return (i);
}

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

  i = 0;
  if (my_strstr_strlen(to_find) == 0)
    return (str);
  while (str[i] != '\0')
    {
      if (str[i] == to_find[0])
	{
	  j = 0;
	  while ((str[i + j] != '\0' && to_find[j] != '\0') &&
		 str[i + j] == to_find[j])
	    {
	      if (to_find[j + 1] == '\0')
		{
		  return (&(str[i]));
		}
	      j = j + 1;
	    }
	}
      i = i + 1;
    }
  return (NULL);
}
