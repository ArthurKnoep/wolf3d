/*
** my_square_root.c for my_square_root in /home/arthur/delivery/CPool_Day05
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Oct  7 14:47:27 2016 Arthur Knoepflin
** Last update Mon Oct 10 20:17:46 2016 Arthur Knoepflin
*/

int	my_square_root(int nb)
{
  long	square_root;

  if (nb == 1)
    return (1);
  if (nb <= 2)
    return (0);
  square_root = 1;
  while (square_root <= nb / 2)
    {
      if (square_root * square_root >= nb)
	{
	  if (square_root * square_root == nb)
	    {
	      return (square_root);
	    }
	  else
	    {
	      return (0);
	    }
	}
      square_root = square_root + 1;
    }
  return (0);
}
