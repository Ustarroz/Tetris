/*
** fct_init_tet.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Mar  4 10:13:01 2016 edouard puillandre
** Last update Fri Mar  4 15:50:25 2016 edouard puillandre
*/

#include "tetris.h"

t_map	*my_def_map()
{
  t_map	*map;
  int	i;
  int	j;

  if ((map = malloc(sizeof(t_map))) == NULL)
    return (NULL);
  map->width = HEIGHT_DEF;
  map->height = WIDTH_DEF;
  if ((map->tab = malloc(sizeof(char *) * (HEIGHT_DEF + 1))) == NULL)
    return (NULL);
  i = - 1;
  while (++i < HEIGHT_DEF)
    {
      j = - 1;
      if ((map->tab[i] = malloc(WIDTH_DEF + 1)) == NULL)
	return (NULL);
      while (++j < WIDTH_DEF)
	map->tab[i][j] = ' ';
      map->tab[i][j] = '\0';
    }
  map->tab[i] = NULL;
  return (map);
}

t_game		*my_def_game()
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->next = true;
  game->lvl = 1;
  game->t.min = 0;
  game->t.sec = 0;
  game->score = 0;
  game->high_score = 0;
}

void	my_def_cmd(t_tetris *tetris)
{
  tetris->cmd[ID_KL].key = my_strdup("kl");
  tetris->cmd[ID_KR].key = my_strdup("kr");
  tetris->cmd[ID_KT].key = my_strdup("kt");
  tetris->cmd[ID_KD].key = my_strdup("kd");
  tetris->cmd[ID_KQ].key = my_strdup("kq");
  tetris->cmd[ID_KP].key = my_strdup("kp");
}

t_tetris	*my_def_tetris()
{
  t_tetris	*tetris;

  if ((tetris = malloc(sizeof(t_tetris))) == NULL)
    return (NULL);
  tetris->debug = false;
  if ((tetris->map = my_def_map()) == NULL)
    return (NULL);
  if ((tetris->game = my_def_game()) == NULL)
    return (NULL);
  my_def_cmd(tetris);
  return (tetris);
}
