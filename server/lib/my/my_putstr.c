/*
** my_putstr.c for my_putstr in /home/arthur/delivery/CPool_Day04
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Oct  6 10:58:44 2016 Arthur Knoepflin
** Last update Thu Dec  1 23:09:57 2016 Arthur Knoepflin
*/
#include "my.h"

int	my_putstr(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      my_putchar(str[count]);
      count = count + 1;
    }
  return (0);
}
