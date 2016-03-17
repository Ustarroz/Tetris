/*
** fct_print.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Mar 16 15:18:59 2016 edouard puillandre
** Last update Thu Mar 17 16:54:15 2016 edouard puillandre
*/

#include "tetris.h"

int	print_map(t_map *map)
{
  int	x;
  int	y;

  y = - 1;
  print_line(map->pos_y, map->pos_x, map->width + 2);
  while (++y < map->height)
    {
      x = - 1;
      mvprintw(map->pos_y + y + 1, map->pos_x, "|");
      mvprintw(map->pos_y + y + 1, map->pos_x + map->width + 2, "|");
      while (++x < map->width)
	if (map->col[y][x] != - 1)
	  {
	    attron(COLOR_PAIR(map->col[y][x] % NB_COL));
	    mvprintw(map->pos_y + y + 1, map->pos_x + x + 1, "*");
	    attron(COLOR_PAIR(NB_COL));
	  }
    }
  print_line(map->pos_y + y, map->pos_x, map->width + 2);
  return (0);
}

int	print_piece_next(t_next *next, int j)
{
  int	x;

  x = - 1;
  while (++x < next->piece->height)
    {
      mvprintw(next->y + j, next->x, "|");
      attron(COLOR_PAIR(next->piece->col % NB_COL));
      mvprintw(next->y + j, next->x + 2, "%s", next->piece->shape[x]);
      attron(COLOR_PAIR(NB_COL));
      mvprintw(next->y + j, next->x + next->width, "|");
      j = j + 1;
    }
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
