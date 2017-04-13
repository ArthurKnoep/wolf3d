/*
** main.c for main in /home/arthur/test_xpm
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Dec 26 18:29:03 2016 Arthur Knoepflin
** Last update Tue Dec 27 16:36:40 2016 Arthur Knoepflin
*/

#include "wolf.h"

t_frame			*load_texture(char **texture)
{
  t_frame		*img;
  t_data		*data;

  data = fill_stru(texture);
  img = my_frame_create(data->width, data->height);
  read_xpm(img, data, texture);
  return (img);
}
