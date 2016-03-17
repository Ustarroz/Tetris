/*
** fct_term.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Mar 11 13:47:41 2016 edouard puillandre
** Last update Thu Mar 17 16:51:21 2016 edouard puillandre
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

void	my_init_color()
{
  init_pair(0, COLOR_RED, COLOR_BLACK);
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  init_pair(3, COLOR_BLUE, COLOR_BLACK);
  init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_WHITE, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

int	start_game(t_tetris *tetris, t_win *win)
{
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
	  my_putstr_error("\n");
	  return (- 1);
	}
      tmp = tmp->next;
    }
  if ((win->win = initscr()) == NULL)
    {
      my_putstr_error(WIN_ERR_MSG);
      return (- 1);
    }
  clear();
  start_color();
  my_init_color();
  return (check_window(win, tetris));
}

int	canonical_mode(struct termios *termios_p, struct termios *save)
{
  if (ioctl(0, TCGETS, save) == - 1)
    return (- 1);
  *termios_p = *save;
  termios_p->c_lflag = ~ (ICANON | ECHO);
  termios_p->c_cc[VMIN] = 0;
  return (0);
}

int			the_game(t_tetris *tetris)
{
  t_win			win;
  bool			loop;
  struct termios	termios_p;
  struct termios	save;

  if (start_game(tetris, &win) == - 1)
    return (- 1);
  loop = true;
  canonical_mode(&termios_p, &save);
  while (loop)
    {
      if (check_window(&win, tetris) == - 1)
	return (- 1);
      termios_p.c_cc[VTIME] = (LVL_MAX - tetris->game->lvl + 1) * 400000;
      if (ioctl(0, TCSETS, &termios_p) == - 1)
	return (- 1);
      got_cmd(tetris, &loop);
      refresh();
    }
  if (ioctl(0, TCSETS, &save) == - 1)
    return (- 1);
  endwin();
  return (0);
}
