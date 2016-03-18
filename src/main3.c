/*
** main.c for PSU_2015_tetris in /home/puilla_e/Semestre2/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Feb 25 18:46:48 2016 edouard puillandre
** Last update Fri Mar 18 16:08:04 2016 edouard puillandre
*/

#include "tetris.h"

int	start_tetris(int argc, char **argv, t_tetris *tetris)
{
  int	check;

  if ((check = my_check_arg(argc, argv, tetris)) == 1)
    {
      my_free_tetris(tetris);
      return (1);
    }
  else if (check == - 1)
    return (- 1);
  if (my_map_tab(tetris) == - 1)
    return (- 1);
  if (tetris->debug == true)
    my_print_debug(tetris);
  my_put_pos(tetris);
  return (0);
}

int		main()
{
  t_piece	*list;
  int		n;
  int		i;
  int		j;
  t_piece	*tmp;

  list = NULL;
  n = files(&list);
  i = - 1;
  tmp = list;
  while (++i < n)
    {
      my_printf("Name %s", tmp->name);
      if (tmp->valid)
	my_printf(" true\n");
      else
	my_printf(" false\n");
      tmp = tmp->next;
    }
  if ((j = rm_elem(&list)) == - 1)
    return (- 1);
  my_printf("\n\nI rm %d files!\n\n", j);
  n = n - j;
  i = - 1;
  tmp = list;
  while (++i < n)
    {
      my_printf("Name %s\n", tmp->name);
      if (tmp->valid)
	my_print_piece(tmp);
      tmp = tmp->next;
    }
  free_list(list);
  return (0);
}
