/*
** my_put_nbr.c for my_put_nbr in /home/arthur/delivery/CPool_Day03
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Oct  5 15:50:24 2016 Arthur Knoepflin
** Last update Mon Nov 21 22:09:01 2016 Arthur Knoepflin
*/
#include "my.h"

int	my_put_nbr(int nb)
{
  int	digit_display;
  long	nb_long;

  nb_long = nb;
  if (nb_long < 0)
    {
      my_putchar('-');
      nb_long *= (-1);
    }
  if (nb_long < 10)
    {
      my_putchar(48 + nb_long);
    }
  else
    {
      digit_display = nb_long % 10;
      nb_long = nb_long / 10;
      my_put_nbr(nb_long);
      my_putchar(48 + digit_display);
    }
  return (0);
}
