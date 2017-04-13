/*
** my_strdup.c for my_strdup in /home/arthur/delivery/CPool_Day08
**
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
**
** Started on  Wed Oct 12 09:41:39 2016 Arthur Knoepflin
** Last update Sat Dec  3 12:52:30 2016 Arthur Knoepflin
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*cpy;
  int	i;

  if ((cpy = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < my_strlen(src))
    {
      cpy[i] = src[i];
      i += 1;
    }
  cpy[i] = '\0';
  return (cpy);
}
