/*
** parse_2.c for parse_2 in /home/arthur/delivery/MUL/wireframe
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Wed Dec  7 22:40:26 2016 Arthur Knoepflin
** Last update Wed Dec  7 22:45:24 2016 Arthur Knoepflin
*/

void	fill_array_2(char c, int *x, int *neg, int *tmp)
{
  if (c == '-')
    *neg = 1;
  else
    {
      *tmp *= 10;
      *tmp += c - '0';
    }
  *x += 1;
}
