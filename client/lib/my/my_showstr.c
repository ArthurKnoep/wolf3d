/*
** my_showstr.c for my_showstr in /home/arthur/delivery/CPool_Day06
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Tue Oct 11 09:13:50 2016 Arthur Knoepflin
** Last update Mon Nov 21 22:08:12 2016 Arthur Knoepflin
*/
#include <stdlib.h>
#include "my.h"

int	my_putnbr_base_length(char *base)
{
  int   	i;

  i = 0;
  while (base[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

int	my_putnbr_base(int nbr, char *base)
{
  int   	digit_display;
  int   	long_base;
  long  	nb_long;

  if (nbr == 0)
    return (0);
  nb_long = nbr;
  long_base = my_putnbr_base_length(base);
  if (nb_long < 0)
    {
      my_putchar('-');
      nb_long *= (-1);
    }
  if  (nb_long < long_base)
    {
      my_putchar(base[nb_long]);
    }
  else
    {
      digit_display = nb_long % long_base;
      nb_long = nb_long / long_base;
      my_putnbr_base(nb_long, base);
      my_putchar(base[digit_display]);
    }
}

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] > 126)
	{
	  my_putchar('\\');
	  if (str[i] < 16);
	    my_putchar('0');
	  my_putnbr_base(str[i], "0123456789abcdef");
	}
      else
	{
	  my_putchar(str[i]);
	}
      i += 1;
    }
  return (0);
}
