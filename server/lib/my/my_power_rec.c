/*
** my_power_rec.c for my_power_rec in /home/arthur/Day05
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Oct  7 11:15:06 2016 Arthur Knoepflin
** Last update Sat Oct  8 18:48:18 2016 Arthur Knoepflin
*/

int	my_power_rec(int nb, int p)
{
  long	power;

  if (p < 0)
    return (0);
  if (p == 0)
    return (1);
  power = nb;
  if (p - 1 > 0)
    {
      power = power * my_power_rec(nb, p - 1);
      nb = power;
    }
  if (nb != power)
    return (0);
  return (power);
}
