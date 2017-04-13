/*
** my_find_prime_sup.c for my_find_prime_sup.c in /home/arthur/delivery/CPool_Day05
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Oct  7 17:18:52 2016 Arthur Knoepflin
** Last update Mon Nov 21 22:10:11 2016 Arthur Knoepflin
*/
#include "my.h"

int	my_find_prime_sup(int nb)
{
  if (!my_is_prime(nb))
    {
      nb = my_find_prime_sup(nb + 1);
    }
  return (nb);
}
