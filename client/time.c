/*
** time.c for time in /home/arthur/wolf3d_5/client
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sat Dec 31 10:56:43 2016 Arthur Knoepflin
** Last update Tue Jan 10 22:53:29 2017 
*/

#include <sys/time.h>
#include <time.h>

unsigned long long	get_tick()
{
  clock_t		tick;
  unsigned long long	ret;

  tick = clock();
  ret = (unsigned long long) (((float) tick / (float) CLOCKS_PER_SEC) * 1000.0);
  return (ret);
}

unsigned long long	get_time()
{
  struct timeval	te;
  unsigned long long	ms;

  gettimeofday(&te, NULL);
  ms = te.tv_sec*1000LL + te.tv_usec/1000;
  return (ms);
}
