/*
** fct_print_game.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/PSU_2015_tetris
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Mar 16 15:27:15 2016 edouard puillandre
** Last update Wed Mar 16 19:03:39 2016 edouard puillandre
*/

#include "tetris.h"

int	print_line(int y, int x, int width)
{
  int	i;

  i = 0;
  mvprintw(y, x + i, "|");
  while (++i < width)
    mvprintw(y, x + i, "-");
  mvprintw(y, x + i, "|");
  return (0);
}

int	print_int(t_game *game, int j, int nb, char *str)
{
  int	i;

  mvprintw(game->y + j, game->x, str);
  i = my_strlen(str);
  mvprintw(game->y + j, game->x + i, "%d", nb);
  mvprintw(game->y + j, game->x + game->width, "|");
  return (0);
}

int		print_time(t_game *game, int j)
{
  int		i;
  time_t	t;
  int		clock;

  mvprintw(game->y + j, game->x, "| Time ");
  i = my_strlen("| Time ");
  time(&t);
  clock = t - game->t;
  mvprintw(game->y + j, game->x + i, "%d:%d", clock / 60, clock % 60);
  mvprintw(game->y + j, game->x + game->width, "|");
  return (0);
}

int	print_game(t_game *game, t_win *win)
{
  int	j;

  j = 0;
  print_line(game->y + j, game->x, game->width);
  j = j + 1;
  print_int(game, j, game->high_score, "| High Score ");
  j = j + 1;
  print_int(game, j, game->score, "| Score ");
  j = j + 1;
  mvprintw(game->y + j, game->x + game->width, "|");
  mvprintw(game->y + j, game->x, "|");
  j = j + 1;
  print_int(game, j, game->lvl, "| Level ");
  j = j + 1;
  print_int(game, j, game->line, "| Line ");
  j = j + 1;
  mvprintw(game->y + j, game->x + game->width, "|");
  mvprintw(game->y + j, game->x, "|");
  j = j + 1;
  print_time(game, j);
  j = j + 1;
  print_line(game->y + j, game->x, game->width);
  j = j + 1;
  (void) win;
  /* box(win->win, game->y, game->x); */
  return (0);
}
