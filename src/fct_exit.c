/*
** fct_exit.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Sat Mar  5 14:16:24 2016 edouard puillandre
** Last update Sat Mar 12 14:31:07 2016 edouard puillandre
*/

#include "tetris.h"

void	my_free_tetris(t_tetris *tetris, bool map_def)
{
  int	i;

  if (map_def)
    {
      i = - 1;
      while (tetris->map->form[++i] != NULL)
	free(tetris->map->form[i]);
      free(tetris->map->form);
    }
  i = - 1;
  while (++i < KEY_LEN)
    free(tetris->cmd[i].key);
  free(tetris->map);
  free(tetris->game);
  free(tetris);
}

void	my_putnbr_error(int nb, bool first)
{
  char	c;

  if (nb == 0 && first)
    {
      c = '0';
      write(2, &c, 1);
    }
  if (nb != 0)
    {
      c = nb % 10 + 48;
      my_putnbr_error(nb / 10, false);
      write(2, &c, 1);
    }
  if (first)
    {
      c= '\n';
      write(2, &c, 1);
    }
}
