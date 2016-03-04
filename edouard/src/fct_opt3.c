/*
** fct_opt3.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 16:54:44 2016 edouard puillandre
** Last update Thu Mar  3 19:01:39 2016 edouard puillandre
*/

#include "tetris.h"

int	set_kt(t_tetris *tetris, int *i, char **argv)
{
  (void) tetris;
  (void) i;
  (void) argv;
  return (0);
}

int	set_kd(t_tetris *tetris, int *i, char **argv)
{
  (void) tetris;
  (void) i;
  (void) argv;
  return (0);
}

int	set_kq(t_tetris *tetris, int *i, char **argv)
{
  (void) tetris;
  (void) i;
  (void) argv;
  return (0);
}

int	set_kp(t_tetris *tetris, int *i, char **argv)
{
  (void) tetris;
  (void) i;
  (void) argv;
  return (0);
}

int	set_debug(t_tetris *tetris, int *i, char **argv)
{
  (void) i;
  (void) argv;
  tetris->debug = true;
  return (0);
}
