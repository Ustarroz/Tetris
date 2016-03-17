/*
** fct_list.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Mar 11 10:43:08 2016 edouard puillandre
** Last update Thu Mar 17 11:17:32 2016 Voyevoda
*/

#include "tetris.h"

int		sort_list(t_piece **list, t_piece *elem)
{
  t_piece	*tmp;

  tmp = *list;
  if (my_strcmp((*list)->name, elem->name) > 0)
    {
      while (tmp->next != *list)
	tmp = tmp->next;
      elem->next = tmp->next;
      tmp->next = elem;
      elem = (*list);
      return (0);
    }
  while (tmp->next != *list && my_strcmp(tmp->next->name, elem->name) < 0)
    tmp = tmp->next;
  if (my_strcmp(tmp->next->name, elem->name) > 0)
    {
      elem->next = tmp->next;
      tmp->next = elem;
      return (0);
    }
  else
    return (-1);
}

int		add_elem(t_piece *elem, t_piece **list)
{
  t_piece	*tmp;

  tmp = *list;
  if (*list == NULL)
    {
      *list = elem;
      (*list)->next = *list;
    }
  else
    {
      if ((sort_list(list, elem)) == -1)
	{
	  while (tmp->next != *list)
	    tmp = tmp->next;
	  elem->next = tmp->next;
	  tmp->next = elem;
	}
    }
  return (0);
}

void	free_list(t_piece *list)
{
  t_piece	*tmp;
  t_piece	*end;

  end = list;
  list = list->next;
  while (list != end)
    {
      tmp = list;
      list = list->next;
      free(tmp);
    }
  free(end);
}

int		rm_elem(t_piece *list)
{
  t_piece	*tmp;
  t_piece	*tmp2;
  int		i;
  int		j;

  j = -1;
  i = 0;
  tmp = list;
  while (tmp->next != list)
    {
      if (tmp->next->valid == false)
	{
	  tmp2 = tmp->next;
	  tmp->next = tmp->next->next;
	  if (tmp2->shape != NULL)
	    while (++j != list->height)
	      free(shape[j]);
	  free(tmp2);
	  i++;
	}
      tmp = tmp->next;
    }
  return (i);
}
