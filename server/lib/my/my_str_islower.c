/*
** my_str_islower.c for my_str_islower in /home/arthur/delivery/CPool_Day06
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Oct 10 16:56:44 2016 Arthur Knoepflin
** Last update Mon Oct 10 17:34:37 2016 Arthur Knoepflin
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] >= 'a' && str[i] <= 'z'))
	return (0);
      i = i + 1;
    }
      return (1);
}
