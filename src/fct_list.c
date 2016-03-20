/*
** fct_list.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Mar 11 10:43:08 2016 edouard puillandre
** Last update Sun Mar 20 12:58:08 2016 edouard puillandre
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

void		free_list(t_piece *list)
{
  t_piece	*tmp;
  t_piece	*tmp2;
  int		k;

  tmp = list->next;
  while (tmp != list)
    {
      k = - 1;
      tmp2 = tmp;
      tmp = tmp->next;
      free(tmp2->name);
      if (tmp2->shape != NULL)
	{
	  while (++k < tmp2->height)
	    free(tmp2->shape[k]);
	  free(tmp2->shape);
	}
      free(tmp2);
    }
  k = -1;
  if (tmp->shape != NULL)
    {
      free(tmp->name);
      while (++k < tmp->height)
	free(tmp->shape[k]);
      free(tmp->shape);
    }
  free(list);
}

int		rm_first_elem(t_piece **list, int *i)
{
  t_piece	*tmp;
  t_piece	*tmp2;

  tmp = *list;
  tmp2 = *list;
  if ((*list)->next == *list)
    {
      tmp = NULL;
    }
  else
    {
      while (tmp->next != *list)
	tmp = tmp->next;
      tmp->next = tmp2->next;
      tmp = tmp->next;
    }
  free_piece(tmp2);
  *list = tmp;
  *i = *i + 1;
  return (0);
}

int		rm_elem(t_piece **list)
{
  t_piece	*tmp;
  t_piece	*tmp2;
  int		i;
  bool		first;
  
  i = 0;
  while (*list != NULL && (*list)->valid == false)
    rm_first_elem(list, &i);
  if ((tmp = (*list)) == NULL)
    return (- 1);
  first = true;
  while (tmp != *list || first == true)
    if (tmp->next->valid == false)
      {
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	free_piece(tmp2);
	i++;
      }
    else
      {
	tmp = tmp->next;
	first = false;
      }
  return (i);
}
