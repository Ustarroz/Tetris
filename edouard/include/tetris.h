/*
** tetris.h for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Feb 25 18:47:38 2016 edouard puillandre
** Last update Thu Mar  3 11:24:38 2016 edouard puillandre
*/

#ifndef		TETRIS_H_
# define	TETRIS_H_

# include <ncurses/curses.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "my.h"
# define PATH_GAME "./ressource/game"
# define TETRIMINO "./tetriminos"

typedef struct	s_cmd
{
  int		kl;
  int		kr;
  int		k_turn;
  int		k_drop;
  int		k_quit;
  int		k_pause;
}		t_cmd;

typedef struct	s_map
{
  int		width;
  int		height;
  char		**tab;
}		t_map;

typedef struct	s_piece
{
  int		width;
  int		height;
  int		col;
  char		**shape;
}		t_piece;

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
  t_cmd		cmd;
  t_map		map;
  t_game	game;
  int		n_piece;
  t_piece	*piece;
}		t_tetris;

#endif /* !TETRIS_H_ */
