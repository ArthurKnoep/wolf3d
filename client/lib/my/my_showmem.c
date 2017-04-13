/*
** my_showmem.c for my_showmem in /home/arthur/delivery/CPool_Day06
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Tue Oct 11 16:57:00 2016 Arthur Knoepflin
** Last update Mon Nov 21 22:00:37 2016 Arthur Knoepflin
*/
#include "my.h"

static void	first_row(int c)
{
  if (c >= 0 && c <= 15)
    my_putstr("0000000");
  if (c > 15 && c <= 255)
    my_putstr("000000");
  if (c > 255 && c <= 4095)
    my_putstr("00000");
  if (c > 4095 && c <= 65535)
    my_putstr("0000");
  if (c > 65535 && c <= 1048575)
    my_putstr("000");
  if (c > 1048575 && c <= 1677715)
    my_putstr("00");
  if (c > 16777215)
    my_putstr("0");
  my_putnbr_base(c, "0123456789abcdef");
  my_putstr(": ");
}

static void	second_row(int l, char *str, int size)
{
  int		i;

  i = l * 16;
  while (i < (l * 16) + 16)
    {
      if (i < size)
	{
	  if (str[i] < 16)
	    my_putchar('0');
	  my_putnbr_base(str[i], "0123456789abcdef");
	  i += 1;
	  if (!(i % 2))
	    my_putchar(' ');
	}
      else
	{
	  my_putstr("  ");
	  i += 1;
	  if (!(i % 2))
	    my_putchar(' ');
	}
    }
}

static void	third_row(int l, char *str, int size)
{
  int		i;

  i = l * 16;
  while (i < (l * 16) + 16)
    {
      if (i < size)
	{
	  if (str[i] < 32 || str[i] > 126)
	    my_putchar('.');
	  else
	    my_putchar(str[i]);
	  i += 1;
	}
      else
	{
	  my_putchar('.');
	  i += 1;
	}
    }
  my_putchar('\n');
}

int	my_showmem(char *str, int size)
{
  int	l;
  int	c;
  int	nb_line;

  l = 0;
  c = 0;
  if (!(size % 16))
    nb_line = size / 16;
  else
    nb_line = (size / 16) + 1;
  while (l < nb_line)
    {
      first_row(c);
      second_row(l, str, size);
      third_row(l, str, size);
      c += 16;
      l += 1;
    }
  return (0);
}
