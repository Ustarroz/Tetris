/*
** fct_score.c for PSU_2015_tetris.h in /home/puilla_e/Semestre2/psu/rendu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Mar 11 11:01:16 2016 edouard puillandre
** Last update Fri Mar 11 12:22:40 2016 edouard puillandre
*/

#include "tetris.h"

int	my_got_high(t_tetris *tetris)
{
  char	*str;
  int	fd;

  if ((fd = open(PATH_SCORE, O_RDONLY)) == - 1)
    {
      my_putstr_error(OPEN_ERR_MSG);
      return (- 1);
    }
  if ((str = get_next_line(fd)) == NULL)
    {
      my_putstr_error(READ_ERR_MSG);
      return (- 1);
    }
  if (check_int(str) == - 1)
    tetris->game->high_score = 0;
  else
    tetris->game->high_score = my_getnbr(str);
  free(str);
  if (close(fd) == - 1)
    {
      my_putstr_error(CLOSE_ERR_MSG);
      return (- 1);
    }
  return (0);
}

int	write_to_fd(int fd, int nb, bool first)
{
  char	c;

  if (first == true || nb != 0)
    {
      if (write_to_fd(fd, nb / 10, false) == - 1)
	return (- 1);
      c = nb % 10 + 48;
      if (write(fd, &c, 1) == - 1)
	{
	  my_putstr_error(WRITE_ERR_MSG);
	  return (- 1);
	}
    }
  return (0);
}

int	my_save_high(t_tetris *tetris)
{
  int	fd;
  int	nb;

  if (tetris->game->score <= tetris->game->high_score)
    nb = tetris->game->high_score;
  else
    nb = tetris->game->score;
  if ((fd = open(PATH_SCORE, O_WRONLY | O_TRUNC)) == - 1)
    {
      my_putstr_error(OPEN_ERR_MSG);
      return (- 1);
    }
  if (write_to_fd(fd, nb, true) == - 1)
    return (- 1);
  if (close(fd) == - 1)
    {
      my_putstr_error(CLOSE_ERR_MSG);
      return (- 1);
    }
  return (0);
}
