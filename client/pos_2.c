/*
** pos_2.c for pos_2 in /home/arthur/wolf3d_3/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Fri Dec 23 16:58:51 2016 Arthur Knoepflin
** Last update Sun Jan  1 18:37:31 2017 Arthur Knoepflin
*/

#include <stdlib.h>

float	get_y_pos(char *buffer, int i)
{
  int	j;
  char	tmp[64];

  j = 0;
  while (buffer[i] && buffer[i] != ';')
    {
      tmp[j] = buffer[i];
      i += 1;
      j += 1;
    }
  tmp[j] = '\0';
  return (atof(tmp));
}

float	get_x_pos(char *buffer, int i)
{
  int	j;
  int	count;
  char	tmp[64];

  j = 0;
  count = 0;
  while (buffer[i] && count < 1)
    {
      if (buffer[i] == ';')
	count += 1;
      i += 1;
    }
  while (buffer[i] && buffer[i] != ';')
    {
      tmp[j] = buffer[i];
      i += 1;
      j += 1;
    }
  tmp[j] = '\0';
  return (atof(tmp));
}

float	get_angle_pos(char *buffer, int i)
{
  int	j;
  int	count;
  char	tmp[64];

  j = 0;
  count = 0;
  while (buffer[i] && count < 2)
    {
      if (buffer[i] == ';')
	count += 1;
      i += 1;
    }
  while (buffer[i] && buffer[i] != ';')
    {
      tmp[j] = buffer[i];
      i += 1;
      j += 1;
    }
  tmp[j] = '\0';
  return (atof(tmp));
}

int	get_life_pos(char *buffer, int i)
{
 int	j;
  int	count;
  char	tmp[64];

  j = 0;
  count = 0;
  while (buffer[i] && count < 3)
    {
      if (buffer[i] == ';')
	count += 1;
      i += 1;
    }
  while (buffer[i] && buffer[i] != ';')
    {
      tmp[j] = buffer[i];
      i += 1;
      j += 1;
    }
  tmp[j] = '\0';
  return (atoi(tmp));
}
