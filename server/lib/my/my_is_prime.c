/*
** my_is_prime.c for my_is_prime in /home/arthur/delivery/CPool_Day05
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Oct  7 15:50:33 2016 Arthur Knoepflin
** Last update Sun Oct  9 12:28:33 2016 Arthur Knoepflin
*/

int	my_is_prime(int nb)
{
  int	count;
  int	nbr;

  count = 1;
  nbr = (nb + 1) / 2;
  while (count < nbr)
    {
      if (count != nb && count != 1)
	{
	  if (nb % count == 0)
	    return (0);
	}
      count = count + 1;
    }
  return (1);
}
