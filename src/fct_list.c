/*
** fct_list.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Mar 11 10:43:08 2016 edouard puillandre
** Last update Sat Mar 12 12:33:22 2016 Voyevoda
*/

#include "tetris.h"

int		add_elem(t_piece *elem, t_piece **list)
{
  t_piece	*tmp;

  tmp = malloc(sizeof(t_piece));
  tmp = *list;
  if (*list == NULL)
    {
      if ((list = malloc(sizeof(t_piece))) == NULL)
	return (-1);
      *list = elem;
      *list->next = list;
    }
  else
    {
      if ((sort_list(list, elem)) = -1);
      {
	while (tmp->next != *list)
	  tmp = tmp->next;
	swap_struct_elem(elem, list, tmp);
	tmp->next = *list;
      }
    }
  return (0);
}

int	swap_struct_elem(t_piece *elem, t_piece **list, t_piece *tmp)
{
  elem->next = tmp->next;
  tmp->next->valid = elem->valid;
  tmp->next->width = elem->width;
  tmp->next->height = list->height;
  tmp->next->col = list->col;
  tmp->next->name = list->name;
  tmp->next->shape = elem->shape;
  tmp->next = elem;
  return (0);
}

int	rm_elem(t_piece *elem, t_piece **list);
{

  return (0);
}

int		sort_list(t_piece **list, t_piece *elem)
{
  t_piece	*tmp;

  if ((tmp = malloc(sizeof(t_piece))) == NULL)
    return (-1);
  tmp = *list;
  if ((mycmp(*list->name, elem->name)) < 0)
    {
      while (tmp->next != list)
	tmp = tmp->next;
      swap_struct_elem(elem, list, tmp);
      return (0);
    }
  while ((tmp->next != *list || mycmp(tmp->next->name, elem->name)) < 0)
    tmp = tmp->next;
  if ((mycmp(list->name, tmp->name)) < 0)
    {
      swap_struct_elem(elem, list, tmp);
      return (0);
    }
  return (-1);
}
