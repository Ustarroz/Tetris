/*
** fct_term.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Mar 11 13:47:41 2016 edouard puillandre
** Last update Wed Mar 16 16:57:31 2016 Voyevoda
*/

#include "tetris.h"

int	check_window(t_win *win, t_tetris *tetris)
{
  getmaxyx(win->win, win->y, win->x);
  if (win->x <= tetris->next->width + tetris->next->x ||
      win->y <= tetris->map->height + tetris->map->pos_y ||
      win->y <= tetris->game->height + tetris->game->y)
    {
      endwin();
      my_putstr_error(TERM_ERR_MSG);
      return (- 1);
    }
  return (0);
}

int	start_game(t_tetris *tetris, t_win *win)
{
  SCREEN	*screen;
  t_piece	*tmp;
  int		i;

  tmp = tetris->piece;
  i = - 1;
  while (++i < tetris->nb_piece)
    {
      if (tmp->width > tetris->map->width || tmp->height > tetris->map->height)
	{
	  my_putstr_error(MAP_ERR_MSG);
	  my_putstr_error(tmp->name);
	  return (- 1);
	}
      tmp = tmp->next;
    }
  if ((win->win = initscr()) == NULL)
    {
      my_putstr_error(WIN_ERR_MSG);
      return (- 1);
    }
  return (check_window(win, tetris));
}

int			the_game(t_tetris *tetris)
{
  t_win			win;
  bool			loop;
  struct termios	termios_p;
  struct termios	save;

  if (start_game(tetris, &win) == - 1)
    return (- 1);
  if (iocstl(0, TCGETS, &save) == - 1)
    return (- 1);
  termios_p = save;
  termios_p.c_lflag = ~ (ICANON | ECHO);
  termios_p.c_cc[VMIN] = 0;
  loop = true;
  while (loop)
    {
      if (check_window(&win, tetris) == - 1)
	return (- 1);
      termios_p.c_cc[VTIME] = (LVL_MAX - tetris->lvl + 1) * 20;
      if (ioctl(0, TCSETS, &termios_p) == - 1)
	return (- 1);
      got_cmd(tetris);
    }
  if (ioctl(0, TCSETS, &save) == - 1)
    return (- 1);
  endwin();
  return (0);
}
