/*
** my_isneg.c for my_isneg in /home/arthur/delivery/CPool_Day03
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Oct  5 11:03:33 2016 Arthur Knoepflin
** Last update Mon Nov 21 22:09:50 2016 Arthur Knoepflin
*/
#include "my.h"

int	my_isneg(int n)
{
  if (n < 0)
    {
      my_putchar('N');
    }
  else
    {
      my_putchar('P');
    }
  return (0);
}
