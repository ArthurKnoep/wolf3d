/*
** my_swap.c for my_swap in /home/arthur/delivery/CPool_Day04
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Thu Oct  6 10:40:58 2016 Arthur Knoepflin
** Last update Thu Oct  6 10:53:22 2016 Arthur Knoepflin
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
