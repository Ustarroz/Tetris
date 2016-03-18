/*
** fct_print.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Mar 16 15:18:59 2016 edouard puillandre
** Last update Fri Mar 18 01:14:00 2016 edouard puillandre
*/

#include "tetris.h"

int	print_piece(t_piece *piece, int x, int y)
{
  int	i;
  int	j;
  char	c;

  attron(COLOR_PAIR(piece->col % NB_COL));
  i = - 1;
  while (++i < piece->height)
    {
      j = - 1;
      while (++j < piece->width)
	{
	  c = piece->shape[i][j];
	  if (c == '*')
	    mvprintw(y + i, x + j, "%c", c);
	}
    }
  attron(COLOR_PAIR(NB_COL));
  return (0);
}

int	print_map(t_map *map)
{
  int	x;
  int	y;

  y = 1;
  print_line(map->pos_y, map->pos_x, map->width + 1);
  while (++y < map->height + 2)
    {
      x = - 1;
      mvprintw(map->pos_y + y - 1, map->pos_x, "|");
      mvprintw(map->pos_y + y - 1, map->pos_x + map->width + 1, "|");
      while (++x < map->width)
	if (map->col[y][x] != - 1)
	  {
	    attron(COLOR_PAIR(map->col[y][x] % NB_COL + 1));
	    mvprintw(map->pos_y + y - 1, map->pos_x + x + 1, "X");
	    attron(COLOR_PAIR(NB_COL));
	  }
    }
  print_line(map->pos_y + y - 1, map->pos_x, map->width + 1);
  return (0);
}

int	print_piece_next(t_next *next, int j)
{
  int	x;

  x = - 1;
  while (++x < next->piece->height)
    {
      mvprintw(next->y + j, next->x, "|");
      mvprintw(next->y + j, next->x + next->width, "|");
      j = j + 1;
    }
  print_piece(next->piece, next->x + 2, next->y + 2);
  return (j);
}

int	print_next(t_next *next)
{
  int	j;

  j = 0;
  mvprintw(next->y + j, next->x + 1, "Next");
  j = j + 1;
  print_line(next->y + j, next->x, next->width);
  j = j + 1;
  j = print_piece_next(next, j);
  print_line(next->y + j, next->x, next->width);
  return (0);
}

int	print_all(t_tetris *tetris)
{
  mvprintw(tetris->map->pos_y, tetris->game->x, NAME_GAME);
  mvprintw(tetris->map->pos_y + 2, tetris->game->x, COPYRIGHT);
  print_game(tetris->game);
  if (tetris->next->valid)
    print_next(tetris->next);
  print_map(tetris->map);
  return (0);
}
