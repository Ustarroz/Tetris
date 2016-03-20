/*
** tetris.h for PSU_2015_tetris in /home/puilla_e/Semestre2/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Thu Feb 25 18:47:38 2016 edouard puillandre
** Last update Sun Mar 20 23:26:33 2016 edouard puillandre
*/

#ifndef		TETRIS_H_
# define	TETRIS_H_

# include <curses.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# include <term.h>
# include <time.h>
# include "my.h"

# define PATH_SCORE "./ressource/high"
# define TETRIMINO "./tetriminos/"
# define INT_MAX "2147483647"
# define ENV_TERM "TERM="
# define WIDTH_DEF (10)
# define HEIGHT_DEF (20)
# define OPT_LEN (11)
# define KEY_LEN (6)
# define ID_KL (0)
# define ID_KR (1)
# define ID_KT (2)
# define ID_KD (3)
# define ID_KQ (4)
# define ID_KP (5)
# define ID_HELP (6)
# define ID_LVL (7)
# define ID_MAP (8)
# define ID_W (9)
# define ID_D (10)
# define READ_SIZE (4078)
# define GAME_POS_X (2)
# define GAME_POS_Y (10)
# define GAME_WIDTH (25)
# define GAME_HEIGHT (9)
# define MAP_POS_X (29)
# define MAP_POS_Y (2)
# define LVL_MAX (10)
# define NB_COL (7)
# define ARG_ERR_MSG "Error: incorrect argument "
# define CAP_ERR_MSG "Error: capability can't be found\n"
# define MALLOC_ERR_MSG "Malloc error\n"
# define READ_ERR_MSG "Read line error\n"
# define OPEN_ERR_MSG "Open error\n"
# define CLOSE_ERR_MSG "Close error\n"
# define WRITE_ERR_MSG "Write error\n"
# define ENV_ERR_MSG "Error: no defined environment\n"
# define MAP_ERR_MSG "Error: the map is too short for the piece "
# define TERM_ERR_MSG "Error: the terminal is too short for this game\n"
# define PATH_ERR_MSG "Error: no directory ./tetriminos/\n"
# define TET_ERR_MSG "Error: can't find any .tetrimino\n"
# define TET2_ERR_MSG "Error: all .tetrimino are wrong\n"
# define WIN_ERR_MSG "Initscr error\n"
# define NAME_GAME "Tetros®"
# define COPYRIGHT "Made in Taiwan"

typedef struct s_tetris * nom;

typedef struct	s_cmd
{
  char		*key;
  int		(*fct)(nom, int *n);
}		t_cmd;

typedef struct		s_piece
{
  bool			valid;
  int			width;
  int			height;
  int			col;
  char			*name;
  char			**shape;
  struct s_piece	*next;
  struct s_piece	*turn;
}			t_piece;

typedef struct	s_map
{
  int		pos_x;
  int		pos_y;
  int		x;
  int		y;
  int		width;
  int		height;
  int		**col;
  t_piece	*piece;
}		t_map;

typedef struct	s_game
{
  int		x;
  int		y;
  int		width;
  int		height;
  int		lvl;
  time_t       	t;
  time_t	pause;
  int		score;
  int		high_score;
  int		line;
}		t_game;

typedef struct	s_next
{
  bool		valid;
  int		x;
  int		y;
  int		width;
  int		height;
  t_piece	*piece;
}		t_next;

typedef struct	s_tetris
{
  bool		debug;
  t_cmd		cmd[KEY_LEN];
  t_map		*map;
  t_game	*game;
  int		nb_piece;
  t_piece	*piece;
  t_next	*next;
}		t_tetris;

typedef struct	s_win
{
  WINDOW	*win;
  int		x;
  int		y;
}		t_win;

typedef struct	s_opt
{
  char		*str;
  char		*eq;
  int		arg;
  int		(*fct_eq)(t_tetris *tetris, int *i, char **argv);
  int		(*fct)(t_tetris *tetris, int *i, char **argv, int argc);
}		t_opt;

int		my_strcmp(char *str, char *ptr);
int		my_strncmp(char *str, char *ptr, int n);
char		*my_strdup(char *str);
int		check_int(char *str);
void		init_tab_opt(t_opt *opt, int argc);
int		set_lvl(t_tetris *tetris, int *i, char **argv, int argc);
int		set_map(t_tetris *tetris, int *i, char **argv, int argc);
int		set_w(t_tetris *tetris, int *i, char **argv, int argc);
int		set_kl(t_tetris *tetris, int *i, char **argv, int argc);
int		set_kr(t_tetris *tetris, int *i, char **argv, int argc);
int		set_kt(t_tetris *tetris, int *i, char **argv, int argc);
int		set_kd(t_tetris *tetris, int *i, char **argv, int argc);
int		set_kq(t_tetris *tetris, int *i, char **argv, int argc);
int		set_kp(t_tetris *tetris, int *i, char **argv, int argc);
int		set_debug(t_tetris *tetris, int *i, char **argv, int argc);
int		set_lvl_eq(t_tetris *tetris, int *i, char **argv);
int		set_map_eq(t_tetris *tetris, int *i, char **argv);
int		set_w_eq(t_tetris *tetris, int *i, char **argv);
int		set_kl_eq(t_tetris *tetris, int *i, char **argv);
int		set_kr_eq(t_tetris *tetris, int *i, char **argv);
int		set_kt_eq(t_tetris *tetris, int *i, char **argv);
int		set_kd_eq(t_tetris *tetris, int *i, char **argv);
int		set_kq_eq(t_tetris *tetris, int *i, char **argv);
int		set_kp_eq(t_tetris *tetris, int *i, char **argv);
int		set_debug_eq(t_tetris *tetris, int *i, char **argv);
t_tetris	*my_def_tetris(char **env);
int		my_def_cmd(t_tetris *tetris, char **env);
int		my_check_arg(int argc, char **argv, t_tetris *tetris);
void		my_putnbr_error(int nb, bool first);
int		my_map_tab(t_tetris *tetris);
void		my_free_tetris(t_tetris *tetris);
int		my_print_debug(t_tetris *tetris);
int		my_got_high(t_tetris *tetris);
int		my_save_high(t_tetris *tetris);
char		*get_next_line(const int fd);
int		malloc_piece(t_piece *piece);
int		files(t_piece **list);
int		load_info(char *str, t_piece **list);
int		add_elem(t_piece *elem, t_piece **list);
int		swap_struc_elem(t_piece *elem, t_piece **list, t_piece *tmp);
int		sort_list(t_piece **list, t_piece *elem);
void		free_list(t_piece *list);
int		the_game(t_tetris *tetris);
int		print_all(t_tetris *tetris);
int		print_game(t_game *game);
int		print_line(int x, int y, int width);
int		got_cmd(t_tetris *tetris, int *n);
void		my_put_pos(t_tetris *tetris);
int		rm_elem(t_piece **list);
int		rm_first_elem(t_piece **list, int *i);
int		fct_quit(t_tetris *tetris, int *n);
int		fct_pause(t_tetris *tetris, int *n);
int		fct_drop(t_tetris *tetris, int *n);
int		fct_turn(t_tetris *tetris, int *n);
int		fct_left(t_tetris *tetris, int *n);
int		fct_right(t_tetris *tetris, int *n);
int		fct_drop(t_tetris *tetris, int *n);
int		check_piece_place(t_map *map);
void		put_piece_place(t_map *map, int nb);
t_piece		*random_piece(t_tetris *tetris);
void		free_piece(t_piece *tmp);
void		my_print_piece(t_piece *tmp);
int		print_piece(t_piece *piece, int x, int y, int nb);
int		my_find_term(char **env);
char		*epur_star(char *str);
int		check_full_line(t_tetris *tetris);

#endif /* !TETRIS_H_ */
