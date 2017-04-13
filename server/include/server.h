/*
** server.h for server in /home/arthur/wolf3d_3/server
** 
** Made by Arthur Knoepflin
** Login   <arthur@epitech.net>
** 
** Started on  Thu Dec 22 10:01:15 2016 Arthur Knoepflin
** Last update Tue Jan 10 22:47:56 2017 
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <SFML/Graphics.h>
# define	INVALID_SOCKET	-1
# define	SOCKET_ERROR	-1
# define	closesocket(s)	close(s)
typedef		int		SOCKET;
typedef	struct	sockaddr_in	SOCKADDR_IN;
typedef	struct	sockaddr	SOCKADDR;
typedef struct	in_addr		IN_ADDR;
# define	CRLF		"\r\n"
# define	BUF_SIZE	2048
# define	CONF_F		"server.conf"

/*
** OPTIONS
*/

# define	NAME		"NAME"
# define	PORT		"PORT"
# define	MAX_PLAYER	"MAX_PLAYER"
# define	MAP		"MAP"

/*
** SERVER
*/

# define	KA_S		"<KILL_ALL>"
# define	RESP_S		"<RESPAWN>"
# define	MAP_S		"<MAP>"
# define	FIRE_S		"<FIRE>"
# define	POS_S		"<POS>"
# define	NB_PLY_S	"<NB_PLY>"
# define	PLY_MAX_S	"<PLY_MAX>"
# define	SET_POS_S	"<SET_POS>"

typedef struct	s_weap
{
  int		weap;
  int		visor;
}		t_weap;

typedef struct		s_conf
{
  int			port;
  int			max_player;
  char			*name;
  char			*map;
  struct s_parse	*parse;
}			t_conf;

typedef struct	s_pos
{
  float		x;
  float		y;
  float		angle;
}		t_pos;

typedef struct		s_client
{
  SOCKET		sock;
  char			name[BUF_SIZE];
  float			x;
  float			y;
  float			angle;
  int			life;
  unsigned long long	time;
}			t_client;

typedef struct	s_nb_cli
{
  int		max;
  int		max_int;
  int		actual;
  struct s_conf	*conf;
}		t_nb_cli;

typedef struct	s_parse
{
  int		**data;
  int		width;
  int		height;
  sfVector2i	sizemap;
  int		width_len;
}		t_parse;

/*
** CONF
** conf.c
*/

int	len_opt(char *, int);
int	get_index(char *, int);
int	is_etx(char);
t_conf	*get_conf();

/*
** check_error.c
*/

void	check_error(t_conf *);

/*
** file.c
*/

int	nb_line(char *);
char	*read_file();

/*
** fill_stru.c
*/

void	fill_stru(t_conf *, char *);

/*
** fill_stru_fnt.c
*/

void	fill_name(t_conf *, char *);
void	fill_port(t_conf *, char *);
void	fill_max_ply(t_conf *, char *);
void	fill_map(t_conf *, char *);

/*
** SERVER
** main.c
*/

void	free_all(t_conf *);

/*
** init_connection.c
*/

int	init_connection(t_conf *);

/*
** client.c
*/

int	new_client(t_client *, t_nb_cli *, fd_set *, SOCKET);
void	client_talk(t_client *, t_nb_cli *, fd_set *, t_conf *);
void	client_disconnect(t_client *, t_nb_cli *, int);

/*
** read_client.c
*/

int	read_client(SOCKET, char *);
int	write_client(SOCKET, char *);

/*
** kill_all.c
*/

void	kill_all(t_client *, int, t_nb_cli *);

/*
** check_pos.c
*/

void	check_pos(t_client *, t_nb_cli *);

/*
** stop.c
*/

void	end_connection(SOCKET);
void	clear_clients(t_client *, int);
void	remove_client(t_client *, int, t_nb_cli *);

/*
** client_msg.c
*/

void	client_treat_msg(t_client *, int, char *, t_nb_cli *);

/*
** my_strncmp.c
*/

int	my_strncmp(char *, char *, int);
int	size_nb(int);
char	*int_to_char(int);

/*
** pos.c
*/

char	*get_all_pos(t_client *, int, t_nb_cli *);
int	len_separator(char *, int);
int	total_len_sep(char *, int);
t_pos	get_pos(char *);

/*
** fire.c
*/

void	rep_client_weap(t_client *, int, t_nb_cli *, t_weap);
int	fire(t_client *, int, t_nb_cli *, t_weap);
void	fill_weapon(char *, t_weap *);

/*
** raycast.c
*/

float	raycast(t_client, float, int **, sfVector2i);

/*
** raycast_enn.c
*/

float	angle_enn(t_client, t_client);
int	is_visible(t_client, t_client, t_parse *);

/*
** trigo.c
*/

double	cosd(double);
double	sind(double);
double	tand(double);

/*
** time.c
*/

unsigned long long	get_tick();

/*
** PARSE
** parse.c
*/

t_parse	*get_parse(char *);

/*
** parse_2.c
*/

void	fill_array_2(char, int *, int *, int *);

/*
** read_file.c
*/

char	*read_f(char *);

/*
** size_file.c
*/

int	get_width(char *);
int	get_height(char *);

#endif /* !SERVER_H_ */
