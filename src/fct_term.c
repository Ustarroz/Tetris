/*
** fct_term.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Mar 11 13:47:41 2016 edouard puillandre
** Last update Tue Mar 15 22:50:43 2016 edouard puillandre
*/

#include "tetris.h"

int	start_game(t_tetris *tetris, t_win *win)
{
  SCREEN	*screen;

  screen = newterm(NULL, stderr, stdin);
  
  (void) tetris;
  return (0);
}

int	the_game(t_tetris *tetris)
{
  t_win	*win;

  start_game(tetris);
  return (0);
}
