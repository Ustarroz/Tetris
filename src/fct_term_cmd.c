/*
** fct_term_cmd.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar 17 22:58:09 2016 edouard puillandre
** Last update Fri Mar 18 00:22:10 2016 edouard puillandre
*/

#include "tetris.h"

int	fct_quit(t_tetris *tetris, int *n)
{
  (void) tetris;
  *n = - 1;
  return (0);
}

int		fct_pause(t_tetris *tetris, int *n)
{
  time_t	t;

  (void) n;
  if (tetris->game->pause == 0)
    tetris->game->pause = time(NULL);
  else
    {
      t = time(NULL);
      tetris->game->t = tetris->game->t + (t - tetris->game->pause);
      tetris->game->pause = 0;
    }
  return (0);
}

int	fct_turn(t_tetris *tetris, int *n)
{
  (void) tetris;
  (void) n;
  return (0);
}
