/*
** fct_print.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Mar 16 15:18:59 2016 edouard puillandre
** Last update Thu Mar 17 14:27:19 2016 edouard puillandre
*/

#include "tetris.h"

int	print_piece_next(t_next *next)
{
  (void) next;
  return (0);
}

int	print_next(t_next *next)
{
  int	j;

  j = 0;
  mvprintw(next->y + j, next->x + 1, "Next");
  j = j + 1;
  print_line(next->y + j, next->x, next->width);
  j = j + 1;
  mvprintw(next->y + j, next->x + next->width, "|");
  mvprintw(next->y + j, next->x, "|");
  j = j + 1;
  j = print_piece_next(next);
  print_line(next->y + j, next->x, next->width);
  j = j + 1;
  mvprintw(next->y + j, next->x + next->width, "|");
  mvprintw(next->y + j, next->x, "|");
  return (0);
}

int	print_all(t_tetris *tetris)
{
  mvprintw(tetris->map->pos_y, tetris->game->x, NAME_GAME);
  mvprintw(tetris->map->pos_y + 2, tetris->game->x, COPYRIGHT);
  print_game(tetris->game);
  if (tetris->next->valid)
    print_next(tetris->next);
  return (0);
}
