/*
** fct_list.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Mar 11 10:43:08 2016 edouard puillandre
** Last update Thu Mar 17 15:20:36 2016 Voyevoda
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
      *list = elem;
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
  t_piece	*tmp2;
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

int	rm_first_elem(t_piece **list, int *i)
{
  t_piece	*tmp;
  t_piece	*tmp2;
  int		k;

  k = -1;
  tmp = list;
  while (tmp->next != *list)
    tmp = tmp->next;
  tmp2 = tmp->next;
  tmp->next = tmp->next->next;
  if (tmp2->shape != NULL)
    {
      while (++k < tmp->height)
	free(tmp->shape[j]);
      free(tmp->shape);
    }
  free(tmp2);
  *list = tmp->next;
  return (++i);
}

int		rm_elem(t_piece **list)
{
  t_piece	*tmp;
  t_piece	*tmp2;
  int		i;
  int		j;

  i = 0;
  tmp = *list;
  while (tmp->next != *list)
    {
      j = -1;
      if (tmp->next->valid == false)
	rm_first_elem(*list, &i);
      tmp = tmp->next;
      tmp2 = tmp->next;
      tmp->next = tmp->next->next;
      if (tmp2->shape != NULL)
	{
	  while (++j != list->height)
	    free(list->shape[j]);
	  free(list->shape);
	}
      free(tmp2);
      i++;
    }
  return (i);
}
