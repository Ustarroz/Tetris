/*
** fct_print.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Mar 16 15:18:59 2016 edouard puillandre
** Last update Wed Mar 16 18:57:35 2016 edouard puillandre
*/

#include "tetris.h"

int	print_all(t_tetris *tetris, t_win *win)
{
  mvprintw(tetris->map->pos_y, tetris->game->x, NAME_GAME);
  mvprintw(tetris->map->pos_y + 2, tetris->game->x, COPYRIGHT);
  print_game(tetris->game, win);
  return (0);
}
