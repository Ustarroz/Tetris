/*
** fct_in_game.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Mar 16 14:58:53 2016 edouard puillandre
** Last update Thu Mar 17 11:19:04 2016 edouard puillandre
*/

#include "tetris.h"

int	got_cmd(t_tetris *tetris, bool *loop)
{
  char	buff[1];

  read(1, buff, 1);
  tetris->next->piece = tetris->piece;
  tetris->map->piece = tetris->piece;
  if (buff[0] == 'q')
    *loop = false;
  print_all(tetris);
  return (0);
}
