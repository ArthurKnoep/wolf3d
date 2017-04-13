/*
** my_str_isprintable.c for my_str_isprintable in /home/arthur/delivery/CPool_Day06
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Oct 10 17:51:54 2016 Arthur Knoepflin
** Last update Mon Oct 10 18:03:56 2016 Arthur Knoepflin
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 32 && str[i] <= 126))
	return (0);
      i = i + 1;
    }
  return (1);
}
