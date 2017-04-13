/*
** wolf.h for wolf3d in /home/arthur/delivery/MUL/wolf3d
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Mon Dec 19 10:05:51 2016 Arthur Knoepflin
** Last update Fri Jan 13 21:55:16 2017 
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef WOLF3D_H_
# define WOLF3D_H_

# define	HEIGHT		720
# define	HEIGHT_WALL	200
# define	MAP_H		150
# define	MAP_W		150
# define	SPEED_MOUSE	10.00
# define	FRAME_RATE	1
# define	WIDTH		1280
# define	SIZE		1024
# define	FOV		60

/*
** SOCKET
*/

# define	INVALID_SOCKET	-1
# define	SOCKET_ERROR	-1
# define	CRLF		"\r\n"
# define	PORT		33000
# define	BUF_SIZE	2048
# define	closesocket(s)	close(s)
typedef	int			SOCKET;
typedef struct sockaddr_in	SOCKADDR_IN;
typedef struct sockaddr		SOCKADDR;
typedef struct in_addr		IN_ADDR;

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

typedef	t_my_framebuffer	t_frame;

typedef struct	s_parse
{
  int		**data;
  int		width;
  int		height;
  sfVector2i	sizemap;
  int		width_len;
}		t_parse;

typedef struct	s_pos
{
  float		x;
  float		y;
  float		angle;
  int		life;
}		t_pos;

typedef struct	s_ply
{
  sfVector2f	pos;
  sfVector2i	ms;
  float		angle;
  int		fov;
  float		direction;
  float		speed_mouse;
  int		side;
  SOCKET	sock;
  float		zoom;
  int		nb_player;
  struct s_pos	*pos_ply;
  struct s_fire	*fire;
  t_frame	*text[8];
  t_frame	*text_enn;
  t_frame	*hud;
  t_frame	*fire_hud;
  t_frame	*awp;
  t_frame	*awp_hud;
  t_frame	*go;
  t_frame	*enn_dead;
  t_frame	*dot_red;
  t_frame	*sky;
  int		i;
  int		life;
}		t_ply;

typedef struct		s_fire
{
  sfMusic		*sound;
  sfMusic		*hit_sound;
  sfMusic		*awp;
  sfMusic		*awp_hit;
  sfMusic		*zoom;
  int			act_weap;
  unsigned long long	time;
  unsigned long long	zoom_time;
}			t_fire;

typedef struct	s_raycast
{
  float		length;
  int		side;
  float		offset;
  int		height_wall;
  int		type_wall;
}		t_raycast;

typedef struct	s_data
{
  int		width;
  int		height;
  int		n_color;
  int		n_char_cl;
}		t_data;

typedef struct		s_var
{
  sfRenderWindow	*win;
  int			nb_frame;
  sfVector2i		mouse;
}			t_var;

/*
** trigo.c
*/

double	cosd(double);
double	sind(double);
double	tand(double);

/*
** parse.c
*/

t_parse	*get_parse(SOCKET);

/*
** parse_2.c
*/

void	fill_array_2(char, int *, int *, int *);

/*
** move_player_2.c
*/

void	move_player_2(t_ply *, t_var *);

/*
** read_file.c
*/

char	*read_file(SOCKET);

/*
** check_stru_syn.c
*/

int	check_stru_syn(char *);

/*
** put_error.c
*/

int	my_puterror(char *);
void	put_error_line(int, char *, int);

/*
** minimap.c
*/

void	draw_square(t_frame *, sfVector2i, sfVector2i, sfColor);
void	minimap(t_frame *, t_parse *, t_ply *);

/*
** draw.c
*/

void	draw(t_frame *, t_parse *, t_ply *, t_var *);

/*
** draw_hud.c
*/

void	draw_hud(t_frame *, t_ply *);

/*
** draw_mp.c
*/

void	draw_all_player(t_frame *, t_parse *, t_pos *, t_ply *);
void	draw_all_view(t_frame *, t_parse *, t_pos *, t_ply *);
void	draw_text(t_frame *, sfVector2i, sfVector2i, t_frame *);
void	draw_skin(t_frame *, t_ply *, t_parse *);

/*
** draw_mp_2.c
*/

void	get_size_img(sfVector2i *, t_ply *);

/*
** draw_sky.c
*/

void	draw_sky(t_frame *, t_ply *, sfVector2i);

/*
** game_over.c
*/

void	game_over(t_frame *, t_ply *, t_parse *);

/*
** size_file.c
*/

int	get_width(char *);
int	get_height(char *);

/*
** clear_screen.c
*/

void	clear_screen(t_frame *, sfColor);
void	clear_scr(sfRenderWindow *, t_frame *);
void	draw_on_scr(sfRenderWindow **, sfTexture **, sfSprite **, t_frame *);

/*
** init_player.c
*/

t_var	*init_var();
t_ply	*init_ply(SOCKET, t_parse *);
void	init_fire(t_ply *);
void	init_texture(t_ply *);

/*
** src/my_put_pixel.c
*/

void	my_put_pixel(t_frame *, int, int, sfColor);

/*
** src/my_draw_line.c
*/

void	my_draw_line(t_frame *, sfVector2i, sfVector2i, sfColor);

/*
** src/raycast.c
*/

float	raycast(sfVector2f, float, int **, sfVector2i);

/*
** raycast.c
*/

t_raycast	raycast_stru(t_ply *, float, int **, sfVector2i);

/*
** raycast_2.c
*/

sfVector2f	ret_inf();
float		get_offset(sfVector2f, sfVector2f, int, sfVector2f);
int		get_type_wall(sfVector2f, sfVector2f, t_ply *, int **);

/*
** raycast_enn.c
*/

float	raycast_enn(sfVector2f, t_pos);
float	angle_enn(t_ply *, sfVector2f, t_pos);
int	is_visible(t_ply *, sfVector2f, t_pos, t_parse *);

/*
** my_frame.c
*/

t_frame	*my_frame_create(int, int);
void	my_frame_destroy(t_frame *);

/*
** create_window.c
*/

sfRenderWindow	*create_window(int, int, char *);

/*
** move_player.c
*/

void	move_player(t_ply *, t_parse *, t_var *);

/*
** color.c
*/

sfColor ground_color();
sfColor	sky_color();

/*
** my_put_pixel_a.c
*/

void	my_put_pixel_hit(t_frame *, int, int);

/*
** connection.c
*/

int	init_connection(char *);
SOCKET	start_connection(char **);

/*
** com.c
*/

int	read_server(SOCKET, char *);
void	write_server(SOCKET, char *);

/*
** my_strncmp.c
*/

int	my_strncmp(char *, char *, int);

/*
** pos.c
*/

void	get_nb_player(t_ply *, int);
t_pos	*get_pos(t_ply *, int);
void	send_pos(t_ply *, int);

/*
** pos_2.c
*/

float	get_y_pos(char *, int);
float	get_x_pos(char *, int);
float	get_angle_pos(char *, int);
int	get_life_pos(char *, int);

/*
** fire.c
*/

void	fire(t_ply *);

/*
** time.c
*/

unsigned long long	get_tick();
unsigned long long	get_time();

/*
** TEXTURE
*/

t_frame	*load_texture(char **);
t_data	*fill_stru(char **);
void	read_xpm(t_frame *, t_data *, char **);
sfColor	search_color(char *, t_data *, char **);
sfColor	get_color(int, int, t_frame *);


#endif /* WOLF3D_H_ */
