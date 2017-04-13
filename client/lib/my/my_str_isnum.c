/*
** my_str_isnum.c for my_str_isnum in /home/arthur/delivery/CPool_Day06
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Oct 10 16:56:44 2016 Arthur Knoepflin
** Last update Mon Oct 10 17:25:54 2016 Arthur Knoepflin
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= '0' && str[i] <= '9'))
	return (0);
      i = i + 1;
    }
      return (1);
}
