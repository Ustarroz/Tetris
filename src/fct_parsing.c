/*
** fct_parsing.c for tetris in /home/voyevoda/rendu/systeme_unix/
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Tue Feb 23 16:59:20 2016 Voyevoda
** Last update Fri Mar 11 16:22:14 2016 Voyevoda
*/
#include "../include/tetris.h"

int	fill_piece(t_piece *alphabet, char *buffer, int line, int *cols)
{
  int	i;
  int	k;

  k = 0;
  i = -1;
  while (buffer[++i] != '\0')
    if (buffer[i] != ' ' && buffer[i] != '*')
      return (-1);
    else if (i > alphabet->width && buffer[i] != ' ')
      return (-1);
  i = -1;
  while (++i != alphabet->width)
    {
      if (buffer[i] == '*' && i <= alphabet->width)
	k++;
      if (i == alphabet->width - 1 && buffer[i] == '*')
	*cols = 1;
      if (i == alphabet->width - 1 && k == 0 && 
	  (line == 0 || line == alphabet->height - 1))
	return (-1);
      alphabet->shape[line][i] = buffer[i];
    }
  return (0);
}

int		fill_struct(t_piece *alphabet, int fd)
{
  char          *buffer;
  int		k;
  int		cols;

  cols = 0;
  k = -1;
  while ((buffer = get_next_line(fd)) != NULL && ++k < alphabet->height)
    {
      if ((fill_piece(alphabet, buffer, k, &cols)) == -1)
	{
	  my_putstr_error(OPEN_ERR_MSG);
	  return (-1);
	}
    }
  if ((buffer == NULL && k < alphabet->height) ||
      (buffer != NULL && k == alphabet->height) || (cols == 0))
    {
      alphabet->valid = false;
      return (-1);
    }
  alphabet->valid = true;
  return (0);
}

int	get_to_space(int i, char *str,t_piece *alphabet)
 {
   char		buffer[12];
   int		j;
   int		k;
   static int	l = 0;

   k = i;
   j = 0;
   buffer[11] = '\0';
   while (j != 9 && str[k] >= '0' && str[k] <= '9')
     buffer[j++] = str[k++];
   buffer[++j] = '\0';
   if (l == 0)
     alphabet->width = my_getnbr(buffer);
   else if (l == 1)
     alphabet->height = my_getnbr(buffer);
   else if (l == 2)
     alphabet->col = my_getnbr(buffer);
   l++;
   if (l == 3)
     l = 0;
   if ((malloc_piece(alphabet)) == -1)
     return (-1);
   return (0);
 }

int	check_tetrimino(char *str, t_piece *alphabet, int fd)
{
  int	i;
  int	tab[3];
  int	j;

  i = -1;
  j = 0;
  while (str[++i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  if ((str[i] != ' ') && (str[i] < '0' || str[i] > '9'))
	     return (-1);
	  else if ((tab[j++] = get_to_space(i, str, alphabet)) == -1)
	     return (-1);
	}
    }
  fill_struct(alphabet, fd);
  return (0);
}

int		load_info(char *av, t_piece *list)
{
  int		fd;
  char		*buffer;
  t_piece	*alphabet;

  fd = open(av, O_RDONLY);
  if ((buffer = get_next_line(fd)) == NULL)
    {
      my_putstr_error(OPEN_ERR_MSG);
      return (-1);
    }
  if ((alphabet = malloc(sizeof(t_piece))) == NULL)
      return (-2);
  if ((check_tetrimino(buffer, alphabet, fd)) == -1)
    return (-1);
  add_elem(alphabet, list);
  return (0);
}