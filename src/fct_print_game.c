/*
** fct_print_game.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/rendu/PSU_2015_tetris
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Mar 16 15:27:15 2016 edouard puillandre
** Last update Wed Mar 16 17:57:34 2016 edouard puillandre
*/

#include "tetris.h"

int	print_line(int x, int y, int width)
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
  t_time	t;
  int		clock;

  mvprintw(game->y + j, game->x, "| Time");
  i = game->width - 7;
  time(&t);
  clock = t - game->t;
  mvprintw(game->y + j, game->x + i, "%d:%d |", clock / 60, clock % 60);
  return (0);
}

int	print_game(t_game *game)
{
  int	j;

  j = 0;
  print_line(game->y + j, game->x, game->width);
  j = j + 1;
  print_int(game, j, game->high_score, "| High Score ");
  j = j + 1;
  print_int(game, j, game->score, "| Score ");
  j = j + 2;
  print_int(game, j, game->lvl, "| Level ");
  j = j + 1;
  print_int(game, j, game->line, "| Line ");
  j = j + 2;
  print_time(game, j);
  j = j + 1;
  print_line(game->y + j, game->x, game->width);
  return (0);
}

