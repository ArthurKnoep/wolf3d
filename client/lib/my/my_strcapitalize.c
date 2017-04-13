/*
** my_strcapitalize.c for my_strcapitalize in /home/arthur/delivery/CPool_Day06
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Oct 10 16:06:47 2016 Arthur Knoepflin
** Last update Mon Nov 21 21:59:21 2016 Arthur Knoepflin
*/
#include "my.h"

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  my_strlowcase(str);
  while (str[i] != '\0')
    {
      if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      else if (((str[i - 1] < '0' || str[i - 1] > '9') && str[i - 1] < 'A' ||
	       str[i - 1] > 'Z' && str[i - 1] < 'a' || str[i - 1] > 'z') &&
	       (str[i] >= 'a' && str[i] <= 'z'))
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
