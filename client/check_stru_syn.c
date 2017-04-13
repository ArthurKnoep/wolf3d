/*
** check_stru_syn.c for check_stru in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Nov 21 19:25:03 2016 Arthur Knoepflin
** Last update Mon Dec 19 11:05:28 2016 Arthur Knoepflin
*/

#include "wolf.h"

static void	modif_i(char *str, int *i)
{
  if (str[*i] != '\0')
    *i += 1;
}

static int	check_stru_syn_2(char *str, int i, int width_line)
{
  int		line_curr;

  line_curr = 0;
  modif_i(str, &i);
  while (str[i])
    {
      if (str[i] == '\n')
	{
	  if (line_curr != width_line && str[i + 1] != '\0')
	    {
	      put_error_line(i, str, width_line);
	      return (1);
	    }
	  else if (line_curr != (width_line - 1) && str[i + 1] == '\0')
	    {
	      put_error_line(i, str, width_line);
	      return (1);
	    }
	  line_curr = 0;
	}
      if (str[i] == ',')
	line_curr += 1;
      i += 1;
    }
  return (0);
}

static int	check_last_char(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i += 1;
  if (i > 0 && str[i - 1] == '\n')
    return (0);
  else
    {
      my_puterror("Il manque un \"\\n\" à la fin du fichier\n");
      return (1);
    }
}

int	check_stru_syn(char *str)
{
  int	i;
  int	width_line;

  if (check_last_char(str))
    return (1);
  i = 0;
  width_line = 0;
  while (str[i] && str[i] != '\n')
    {
      if (str[i] == ',')
	width_line += 1;
      i += 1;
    }
  if (check_stru_syn_2(str, i, width_line))
    return (1);
  return (0);
}
