/*
** time.c for time in /home/arthur/wolf3d_6/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Sat Dec 31 10:56:43 2016 Arthur Knoepflin
** Last update Mon Jan  9 16:40:00 2017 Arthur Knoepflin
*/

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <sys/time.h>
#include "server.h"

unsigned long long	get_tick()
{
  struct timeval	te;
  unsigned long long	ms;

  gettimeofday(&te, NULL);
  ms = te.tv_sec*1000LL + te.tv_usec/1000;
  return (ms);
}
