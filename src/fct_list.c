/*
** fct_list.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
**
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
**
** Started on  Fri Mar 11 10:43:08 2016 edouard puillandre
** Last update Tue Mar 15 10:04:52 2016 edouard puillandre
*/

#include "tetris.h"

int	swap_struct_elem(t_piece *elem, t_piece *tmp)
{
  elem->next = tmp->next;
  tmp->next = elem;
  /* elem->next = tmp->next; */
  /* tmp->next->valid = elem->valid; */
  /* tmp->next->width = elem->width; */
  /* tmp->next->height = elem->height; */
  /* tmp->next->col = elem->col; */
  /* tmp->next->name = elem->name; */
  /* tmp->next->shape = elem->shape; */
  /* tmp->next = elem; */
  return (0);
}

int		sort_list(t_piece **list, t_piece *elem)
{
  t_piece	*tmp;
 
  if ((tmp = malloc(sizeof(t_piece))) == NULL)
    return (-1);
  tmp = *list;
  if ((my_strcmp((*list)->name, elem->name)) < 0)
    {
      while (tmp->next != *list)
	tmp = tmp->next;
      swap_struct_elem(elem, *list);
      return (0);
    }
  while ((tmp->next != *list || my_strcmp(tmp->next->name, elem->name)) >= 0)
    tmp = tmp->next;
  if ((my_strcmp((*list)->name, tmp->name)) < 0)
    {
      swap_struct_elem(elem, tmp);
      return (0);
    }
  return (-1);
}

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
      (*list)->next = *list;
    }
  else
    {
      if ((sort_list(list, elem)) == -1)
	{
	  while (tmp->next != *list)
	    tmp = tmp->next;
	  swap_struct_elem(elem, tmp);
	  /* tmp->next = *list; */
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

void		rm_elem(t_piece *list)
{
  t_piece	*tmp;
  t_piece	*tmp2;

  while (tmp->next != list)
    {
      if (tmp->next->valid == false)
	{
	  tmp2 = tmp->next;
	  tmp->next = tmp->next->next;
	  free(tmp2);
	}
      tmp = tmp->next;
    }
}
