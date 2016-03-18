/*
** fct_list.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Mar 11 10:43:08 2016 edouard puillandre
** Last update Fri Mar 18 11:43:33 2016 Voyevoda
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

  tmp = list;
  while (tmp->next != list)
    {
      k = - 1;
      tmp2 = tmp;
      tmp = tmp->next;
      while (++k < tmp2->height)
	free(tmp2->shape[k]);
      free(tmp2->shape);
      tmp2->next = NULL;
      free(tmp2);
    }
  k = -1;
  while (++k < tmp->height)
    free(tmp->shape[k]);
  free(tmp->shape);
  free(list);
}

int	rm_first_elem(t_piece **list, int *i)
{
  t_piece	*tmp;
  t_piece	*tmp2;
  int		k;

  k = -1;
  tmp = *list;
  tmp2 = *list;
  while (tmp->next != *list)
    tmp = tmp->next;
  tmp->next = tmp2->next;
  if (tmp2->shape != NULL)
    {
      while (++k < tmp2->height)
	free(tmp2->shape[k]);
      free(tmp2->shape);
    }
  tmp2->next = NULL;
  free(tmp2);
  *list = tmp;
  return ((++*i));
}

int		rm_elem(t_piece **list)
{
  t_piece	*tmp;
  t_piece	*tmp2;
  int		i;
  int		j;

  i = 0;
  tmp = (*list);
  while (tmp->next != *list)
    {
      j = - 1;
      if ((*list)->valid == false)
	rm_first_elem(list, &i);
      tmp2 = tmp;
      tmp = tmp->next;
      if (tmp->valid == false)
	{
	  tmp2->next = tmp2->next->next;
	  tmp2 = tmp;
	  tmp = tmp->next;
	  if (tmp2->shape != NULL)
	    {
	      while(++j < tmp2->height)
		free(tmp2->shape[j]);
	      free(tmp2->shape);
	    }

	  tmp2->next = NULL;
	  free(tmp2);
	}
    }
  i++;
  return (i);
}
