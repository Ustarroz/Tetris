/*
** fct_term_cmd2.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Mar 18 00:12:47 2016 edouard puillandre
** Last update Fri Mar 18 14:06:08 2016 edouard puillandre
*/

#include "tetris.h"

int	fct_left(t_tetris *tetris, int *n)
{
  (void) n;
  put_piece_place(tetris->map, - 1);
  tetris->map->x = tetris->map->x - 1;
  if (check_piece_place(tetris->map) == - 1)
    tetris->map->x = tetris->map->x + 1;
  put_piece_place(tetris->map, tetris->map->piece->col);
  return (0);
}

int	fct_right(t_tetris *tetris, int *n)
{
  (void) n;
  put_piece_place(tetris->map, - 1);
  tetris->map->x = tetris->map->x + 1;
  if (check_piece_place(tetris->map) == - 1)
    tetris->map->x = tetris->map->x - 1;
  put_piece_place(tetris->map, tetris->map->piece->col);
  return (0);
}

t_piece		*random_piece(t_tetris *tetris)
{
  t_piece	*tmp;
  int		i;
  int		end;

  end = rand() % tetris->nb_piece;
  i = - 1;
  tmp = tetris->piece;
  while (++i < end)
    tmp = tmp->next;
  return (tmp);
}

int	fct_drop(t_tetris *tetris, int *n)
{
  put_piece_place(tetris->map, - 1);
  tetris->map->x = tetris->map->y + 1;
  while (check_piece_place(tetris->map) != - 1)
    tetris->map->x = tetris->map->y + 1;
  tetris->map->x = tetris->map->y - 1;
  put_piece_place(tetris->map, tetris->map->piece->col + NB_COL);
  tetris->map->piece = tetris->map->next;
  tetris->map->x = tetris->map->width + 1 / 2;
  tetris->map->y = 0;
  tetris->next->piece = random_piece(tetris);
  *n = 0;
  return (0);
}
