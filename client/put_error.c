/*
** put_error.c for put_error in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sat Dec  3 14:53:56 2016 Arthur Knoepflin
** Last update Thu Dec 29 12:11:24 2016 Arthur Knoepflin
*/

#include <unistd.h>
#include "wolf.h"

int	my_puterror(char *str)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  while (str[i])
    {
      ret += write(2, &str[i], 1);
      i += 1;
    }
  return (ret);
}

int	my_put_nbr_err(int nbr)
{
  char	disp;
  int	ret;

  ret = 0;
  if (nbr < 0)
    {
      ret += write(2, "-", 1);
      nbr *= -1;
    }
  if (nbr < 10)
    {
      disp = nbr + '0';
      ret += write(2, &disp, 1);
    }
  else
    {
      disp = (nbr % 10) + '0';
      my_put_nbr_err(nbr / 10);
      ret += write(2, &disp, 1);
    }
  return (ret);
}

void	put_error_line(int line, char *str, int width_line)
{
  int	i;
  int	nb_line;

  nb_line = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	nb_line += 1;
      i += 1;
    }
  my_puterror("Erreur à la ligne ");
  my_put_nbr_err(line / nb_line);
  if (width_line != 0)
    {
      my_puterror(" au ");
      my_put_nbr_err(line % width_line);
      my_puterror(" charactere");
    }
  my_puterror("\n");
}
