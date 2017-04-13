/*
** my_revstr.c for my_revstr in /home/arthur/delivery/CPool_Day06
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Mon Oct 10 10:22:27 2016 Arthur Knoepflin
** Last update Thu Oct 13 22:07:55 2016 Arthur Knoepflin
*/

static int	my_rev_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

char	*my_revstr(char *str)
{
  int	len;
  int	i;
  char	temp;

  len = my_rev_strlen(str);
  i = 0;
  while (i < (len / 2))
    {
      temp = str[i];
      str[i] = str[(len - i) - 1];
      str[(len - i) - 1] =  temp;
      i = i + 1;
    }
  return (str);
}
