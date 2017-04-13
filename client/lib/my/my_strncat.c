/*
** my_strncat.c for my_strncat in /home/arthur/delivery/CPool_Day07
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Oct 11 12:47:24 2016 Arthur Knoepflin
** Last update Tue Oct 11 13:31:32 2016 Arthur Knoepflin
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i += 1;
  while (src[j] != '\0' && (j < nb || nb < 0))
    {
      dest[i + j] = src[j];
      j += 1;
    }
  dest[i + j + 1] = '\0';
  return (dest);
}
