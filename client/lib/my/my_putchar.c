/*
** my_putchar.c for my_putchar in /home/arthur/delivery/CPool_Day07/dont_push
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Tue Oct 11 11:08:52 2016 Arthur Knoepflin
** Last update Mon Nov 21 22:09:29 2016 Arthur Knoepflin
*/
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
