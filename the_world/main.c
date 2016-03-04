/*
** main.c for tetris in /home/voyevoda/rendu/systeme_unix/PSU_2015bstetris
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Tue Feb 23 16:59:20 2016 Voyevoda
** Last update Fri Mar  4 13:01:22 2016 Voyevoda
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "./struct.h"

int	fill_piece(char *str, t_piece *alphabet, int nb)
{
  int	i;
  char	*buffer;

  fd = open(av, O_RDONLY);
  if ((buffer = get_next_line(fd)) == NULL)
    {
      fprintf(stderr, "OPEN ERROR\n");
      return (-1);
    }
  i = 0;
  while (str[i] != '\0')
    {
      if (i > alphabet->width && str[i] != ' ')
	return (-1);
      if (nb >= alphabet->height)
	return (-1);
    }
  i = -1;
  while (str[++i] != '\0')
    alphabet->shape[nb][i] = str[i];
  return (0):
}

int	fill_struct(int *tab, t_piece *alphabet, int flag)
{
  int           fd;
  char          *buffer;
  int		i;
  int		k;

  i = k = 0;
  fd = open(av, O_RDONLY);
  if ((buffer = get_next_line(fd)) == NULL)
    {
      fprintf(stderr, "OPEN ERROR\n");
      return (-1);
    }
  while (buffer[++i] != '\0')
    {
      if (buffer[i] != ' ' || buffer[i] != '*')
	return (-1);
      if (i > alphabet->width && buffer[i] != ' ')
	return (-1);
      if (fill_piece(alphabet, i));
    }
    return (0);
}

int		get_to_space(int i, char *str,t_piece *alphabet)
 {
  char		buffer[12];
  int		j;
  int		k;
  static int	l = 0;

  k = i;
  j = 0;
  buffer[11] = '\0';
  while (j != 9 && str[k] <= '0' && str[k] >= '9')
    buffer[j++] = str[k++];
  if (str[k] < '0' || str[k] > '9')
    return (-1);
  if (l = 0)
    alphabet->width = my_getnbr(buffer);
  else if (l = 1)
    alphabet->height = my_getnbr(buffer);
  else if (l = 2)
    alphabet->col = my_getnbr(buffer);
  l++;
  if (l == 3)
    l = 0;
  return (0);
}

int	check_tetrimino(char *str, t_piece *alphabet)
{
  int	i;
  int	tab[3];
  char	*buf;
  int	j;

  i = -1;
  j = 0;
  while (str[++i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  if ((tab[j++] = get_to_space(i, str, alphabet)) == -1)
	    return (-1);
	  else if ((str[i] != ' ') && str[i] < '0' || str[i] > '9')
	    return (-1)
	      }
    }
  fill_struct(tab; alphabet);
  return (tab);
}

int		load_info(char *av)
{
  int		fd;
  char		*buffer;
  t_piece	*alphabet;

  fd = open(av, O_RDONLY);
  if ((buffer = get_next_line(fd)) == NULL)
    {
      fprintf(stderr, "OPEN ERROR\n");
      return (-1);
    }
  alphabet = malloc(sizeof(t_piece));
  malloc_piece(alphabet);
  check_tetrimino(buffer);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 2)
    {
      if (load_info != 0)
	return(-1);
    }
  else
    {
      load_info(av[1]);
    }
    return(0);
}
