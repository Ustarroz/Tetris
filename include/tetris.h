/*
** tetris.h for PSU_2015_tetris in /home/puilla_e/Semestre2/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Thu Feb 25 18:47:38 2016 edouard puillandre
** Last update Sat Mar  5 15:10:47 2016 Voyevoda
*/

#ifndef		TETRIS_H_
# define	TETRIS_H_

/* # include <ncurses/curses.h> */
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "my.h"
# include "get_next_line.h"

# define PATH_GAME "./ressource/game"
# define TETRIMINO "./tetriminos"
# define INT_MAX "2147483647"
# define WIDTH_DEF (12)
# define HEIGHT_DEF (22)
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

typedef struct	s_cmd
{
  char		*key;
  int		(*fct)();
}		t_cmd;

typedef struct	s_map
{
  int		width;
  int		height;
  char		**tab;
}		t_map;

typedef struct		s_piece
{
  int			width;
  int			height;
  int			col;
  char			**shape;
  struct s_piece	*next;
}			t_piece;

typedef struct	s_clock
{
  int		min;
  int		sec;
}		t_clock;

typedef struct	s_game
{
  bool		next;
  int		lvl;
  t_clock	t;
  int		score;
  int		high_score;
}		t_game;

typedef struct	s_tetris
{
  bool		debug;
  t_cmd		cmd[KEY_LEN];
  t_map		*map;
  t_game	*game;
  int		n_piece;
  t_piece	*piece;
}		t_tetris;

typedef struct	s_opt
{
  char		*str;
  char		*eq;
  int		(*fct)(t_tetris *tetris, int *i, char **argv);
}		t_opt;

int		my_strcmp(char *str, char *ptr);
int		my_strncmp(char *str, char *ptr, int n);
char		*my_strdup(char *str);
int		check_int(char *str);
void		init_tab_opt(t_opt *opt);
int		set_lvl(t_tetris *tetris, int *i, char **argv);
int		set_map(t_tetris *tetris, int *i, char **argv);
int		set_w(t_tetris *tetris, int *i, char **argv);
int		set_kl(t_tetris *tetris, int *i, char **argv);
int		set_kr(t_tetris *tetris, int *i, char **argv);
int		set_kt(t_tetris *tetris, int *i, char **argv);
int		set_kd(t_tetris *tetris, int *i, char **argv);
int		set_kq(t_tetris *tetris, int *i, char **argv);
int		set_kp(t_tetris *tetris, int *i, char **argv);
int		set_debug(t_tetris *tetris, int *i, char **argv);
t_tetris	*my_def_tetris();
int		my_check_arg(int argc, char **argv, t_tetris *tetris);
void		malloc_piece(t_piece *alphabet);
int		files();

#endif /* !TETRIS_H_ */
