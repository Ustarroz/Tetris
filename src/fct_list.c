/*
** fct_list.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Fri Mar 11 10:43:08 2016 edouard puillandre
** Last update Fri Mar 11 19:58:49 2016 Voyevoda
*/

#include "tetris.h"

int		add_elem(t_piece *elem, t_piece **list)
{
  t_piece	*tmp;

  tmp = *list;
  if (*list == NULL)
    {
      *list = elem;
      *list->next = list;
    }
  else
    {
      if ((sort_list(list, elem)) = -1);
      {
	while (tmp->next != *list)
	  tmp->next = list;
	tmp->next = elem;
      }
    }
  return (0);
}

/* int	swap_struct_elem(t_piece *elem, t_piece **list) */
/* { */
  
/*   return (0); */
/* } */

int	rm_elem(t_piece *elem, t_piece **list);
{

  return (0);
}

int	sort_list(t_piece **list, t_piec *elem)
{
  t_piece	*tmp;
  t_piece	*tmp2;
  
  tmp = *list;
  tmp2 = *elem;
  while ((tmp->next != *list || mycmp(list->next->name, tmp->name)) >=0)
    tmp->next;
  if ((mycmp(list->name, tmp->name)) < 0)
    {
      tmp2->next = tmp->next;
      tmp->next = tmp2;
    }
  return (0);
}

int	rm_error(t_piece **list)
{

  return (0);
}
