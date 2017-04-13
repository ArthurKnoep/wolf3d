/*
** my_strcpy.c for my_strcpy in /home/arthur/delivery/CPool_Day06
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Oct 10 09:49:08 2016 Arthur Knoepflin
** Last update Mon Oct 10 10:16:24 2016 Arthur Knoepflin
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
