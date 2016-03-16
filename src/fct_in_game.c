/*
** fct_in_game.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Mar 16 14:58:53 2016 edouard puillandre
** Last update Wed Mar 16 18:05:54 2016 edouard puillandre
*/

#include "tetris.h"

int	got_cmd(t_tetris *tetris, bool *loop)
{
  int	i;
  char	buff[1];

  read(1, buff, 1);
  if (buff[0] == 'q')
    *loop = false
  print_all(tetris);
  return (0);
}
