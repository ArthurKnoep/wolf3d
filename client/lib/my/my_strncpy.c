/*
** my_strncpy.c for my_strncpy in /home/arthur/delivery/CPool_Day06
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Oct 10 09:49:08 2016 Arthur Knoepflin
** Last update Tue Dec 27 19:51:50 2016 Arthur Knoepflin
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[n] = '\0';
  return (dest);
}
