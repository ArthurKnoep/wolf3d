/*
** my_sort_int_tab.c for my_sort_int_tab in /home/arthur/delivery/CPool_Day04
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Oct 11 10:13:46 2016 Arthur Knoepflin
** Last update Mon Nov 21 22:00:15 2016 Arthur Knoepflin
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	stop;
  int	temp;

  stop = 0;
  while (!stop)
    {
      i = 1;
      stop = 1;
      while (i < size)
	{
	  if (tab[i - 1] > tab[i])
	    {
	      stop = 0;
	      temp = tab[i - 1];
	      tab[i - 1] = tab[i];
	      tab[i] = temp;
	    }
	  i += 1;
	}
    }
}
