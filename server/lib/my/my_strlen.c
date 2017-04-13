/*
** my_strlen.c for my_strlen in /home/arthur/delivery/CPool_Day04
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Oct  6 11:42:43 2016 Arthur Knoepflin
** Last update Thu Dec  1 18:15:34 2016 Arthur Knoepflin
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	count;

  if (str == NULL)
    return (0);
  count = 0;
  while (str[count] != 0)
    {
      count = count + 1;
    }
  return (count);
}
