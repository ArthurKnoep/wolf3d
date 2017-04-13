/*
** my_getnbr_2.c for my_getnbr in /home/arthur/delivery/CPool_Day10/do-op
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Fri Oct 14 11:01:44 2016 Arthur Knoepflin
** Last update Fri Oct 14 11:20:19 2016 Arthur Knoepflin
*/

int	my_getnbr(char *str)
{
  int	i;
  int	neg;
  long	ret;

  i = 0;
  neg = 0;
  ret = 0;
  while (str[i] && (str[i] == '-' || str[i] == '+'))
    {
      if (str[i] == '-')
	neg += 1;
      i += 1;
    }
  while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
      if (neg % 2)
	ret = (ret * 10) - (str[i] - 48);
      else
	ret = (ret * 10) + (str[i] - 48);
      i += 1;
      if (ret < -2147483648 || ret > 2147483647)
        return (0);
    }
  return (ret);
}
