/*
** fct_in_game.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Mar 16 14:58:53 2016 edouard puillandre
** Last update Fri Mar 18 00:22:33 2016 edouard puillandre
*/

#include "tetris.h"

void	print_and_n(t_tetris *tetris, int *n)
{
  *n = *n + 1;
  if (*n == LVL_MAX - tetris->game->lvl + 1)
    {
      *n = 0;
    }
  print_all(tetris);
}

int	take_cmd(t_tetris *tetris, int *n)
{
  int	i;
  char	buff[10];
  int	ret;

  i = - 1;
  if ((ret = read(1, buff, 1)) == - 1)
    {
      my_putstr_error(READ_ERR_MSG);
      return (- 1);
    }
  buff[ret] = '\0';
  while (++i < KEY_LEN)
    if (my_strcmp(buff, tetris->cmd[i].key) == 0)
      return (tetris->cmd[i].fct(tetris, n));
  return (0);
}

int	got_cmd(t_tetris *tetris, int *n)
{
  tetris->next->piece = tetris->piece;
  tetris->map->piece = tetris->piece;
  if (take_cmd(tetris, n) == - 1)
    return (- 1);
  if (*n != - 1 && tetris->game->pause == 0)
    print_and_n(tetris, n);
  return (0);
}
