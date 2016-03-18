/*
** fct_init_tet.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Mar  4 10:13:01 2016 edouard puillandre
** Last update Fri Mar 18 17:47:32 2016 edouard puillandre
*/

#include "tetris.h"

void		my_put_pos(t_tetris *tetris)
{
  int		width;
  t_piece	*tmp;
  int		i;

  width = MAP_POS_X - (GAME_POS_X + tetris->game->width);
  tetris->map->pos_x = MAP_POS_X;
  tetris->map->pos_y = MAP_POS_Y;
  tetris->next->x = MAP_POS_X + width + tetris->map->width + 2;
  tetris->next->y = MAP_POS_Y;
  tmp = tetris->piece;
  tetris->next->width = tmp->width;
  tetris->next->height = tmp->height;
  i = - 1;
  while (++i < tetris->nb_piece)
    {
      if (tmp->height > tetris->next->height)
	tetris->next->height = tmp->height;
      if (tmp->width > tetris->next->width)
	tetris->next->width = tmp->width;
      tmp = tmp->next;
    }
  tetris->next->width = tetris->next->width + 3;
  tetris->next->height = tetris->next->height + 5;
  tetris->game->t = time(NULL);
}

int	my_map_tab(t_tetris *tetris)
{
  int	i;
  int	j;

  if ((tetris->map->col = malloc(sizeof(int *) * (tetris->map->height + 3)))
      == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (- 1);
    }
  i = - 1;
  while (++i < tetris->map->height + 2)
    {
      j = - 1;
      if ((tetris->map->col[i] = malloc(sizeof(int) * tetris->map->width))
	  == NULL)
	{
	  my_putstr_error(MALLOC_ERR_MSG);
	  return (- 1);
	}
      while (++j < tetris->map->width)
	tetris->map->col[i][j] = - 1;
    }
  tetris->map->col[i] = NULL;
  return (0);
}

t_map	*my_def_map()
{
  t_map	*map;

  if ((map = malloc(sizeof(t_map))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  map->width = WIDTH_DEF;
  map->height = HEIGHT_DEF;
  map->col = NULL;
  return (map);
}

t_game		*my_def_game()
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  game->lvl = 1;
  game->score = 0;
  game->pause = 0;
  game->high_score = 0;
  game->width = GAME_WIDTH;
  game->height = GAME_HEIGHT;
  game->x = GAME_POS_X;
  game->y = GAME_POS_Y;
  return (game);
}

t_tetris	*my_def_tetris(char **env)
{
  t_tetris	*tetris;

  if ((tetris = malloc(sizeof(t_tetris))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  tetris->piece = NULL;
  if ((tetris->nb_piece = files(&(tetris->piece))) == - 1)
    return (NULL);
  tetris->debug = false;
  if ((tetris->map = my_def_map()) == NULL)
    return (NULL);
  if ((tetris->next = malloc(sizeof(t_next))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  tetris->next->valid = true;
  if ((tetris->game = my_def_game()) == NULL)
    return (NULL);
  if (my_def_cmd(tetris, env) == - 1)
    return (NULL);
  return (tetris);
}
