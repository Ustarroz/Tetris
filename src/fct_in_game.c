/*
** fct_in_game.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Wed Mar 16 14:58:53 2016 edouard puillandre
** Last update Fri Mar 18 23:56:29 2016 edouard puillandre
*/

#include "tetris.h"

int	check_piece_place(t_map	*map)
{
  int	x;
  int	y;
  int	w;
  int	h;

  w = (map->piece->width - 1) / 2;
  h = (map->piece->height - 1) / 2;
  y = map->y - h - 1;
  while (++y < map->y - h + map->piece->height)
    {
      x = map->x - w - 1;
      while (++x < map->x - w + map->piece->width &&
	     map->piece->shape[y - map->y + h][x - map->x + w] != '\0')
	if (map->piece->shape[y - map->y + h][x - map->x + w] == '*' &&
	  (x < 0 || x >= map->width || y >= map->height + 2 ||
	   (y > 0 && map->col[y][x] >= NB_COL)))
	  return (- 1);
    }
  return (0);
}

void	put_piece_place(t_map *map, int nb)
{
  int	x;
  int	y;
  int	w;
  int	h;

  w = (map->piece->width - 1) / 2;
  h = (map->piece->height - 1) / 2;
  y = map->y - h - 1;
  while (++y < map->y - h + map->piece->height)
    {
      x = map->x - w - 1;
      while (++x < map->x - w + map->piece->width &&
	     map->piece->shape[y - map->y + h][x - map->x + w] != '\0')
	if (map->piece->shape[y - map->y + h][x - map->x + w] == '*'
	    && y >= 0)
	  map->col[y][x] = nb;
    }
}

void	print_and_n(t_tetris *tetris, int *n)
{
  if (*n == LVL_MAX - tetris->game->lvl + 1)
    {
      *n = 0;
      put_piece_place(tetris->map, - 1);
      tetris->map->y = tetris->map->y + 1;
      if (check_piece_place(tetris->map) == - 1)
	{
	  tetris->map->y = tetris->map->y - 1;
	  /* if (tetris->map->y == (tetris->map->piece->height - 1) / 2) */
	  if (tetris->map->y == 0)
	    {
	      *n = - 1;
	      return ;
	    }
	  put_piece_place(tetris->map, tetris->map->piece->col + NB_COL);
	  tetris->map->piece = tetris->next->piece;
	  print_piece(tetris->next->piece, tetris->next->x + 2,
		      tetris->next->y + 2, NB_COL);
	  tetris->next->piece = random_piece(tetris);
	  tetris->map->x = (tetris->map->width - 1) / 2;
	  /* tetris->map->y = (tetris->map->piece->height - 1) / 2; */
	  tetris->map->y = 0;
	}
      else
	put_piece_place(tetris->map, tetris->map->piece->col);
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
  if (take_cmd(tetris, n) == - 1)
    return (- 1);
  if (*n != - 1 && tetris->game->pause == 0)
    {
      *n = *n + 1;
      print_and_n(tetris, n);
    }
  return (0);
}
