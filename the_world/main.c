/*
** main.c for tetris in /home/voyevoda/rendu/systeme_unix/PSU_2015bstetris
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Tue Feb 23 16:59:20 2016 Voyevoda
** Last update Fri Mar  4 19:45:22 2016 Voyevoda
*/
#include "../include/tetris.h"

int	fill_piece(t_piece *alphabet, int nb, int fd, char *av)
{
  int	i;
  char	*buffer;

  if ((buffer = get_next_line(fd)) == NULL)
    {
      fprintf(stderr, "OPEN ERROR\n");
      return (-1);
    }
  i = 0;
  while (buffer[i] != '\0')
    {
      if (i > alphabet->width && buffer[i] != ' ')
	return (-1);
      if (nb >= alphabet->height)
	return (-1);
    }
  i = -1;
  while (buffer[++i] != '\0')
    alphabet->shape[nb][i] = buffer[i];
  return (0);
}

int	fill_struct(int *tab, t_piece *alphabet, char *av)
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
      if (fill_piece(alphabet, i, fd, av));
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
   while (j != 9 && str[k] >= '0' && str[k] <= '9')
     buffer[j++] = str[k++];
   buffer[++j] = '\0';
   printf("buffer%s\n", buffer);
   if (l = 0)
     alphabet->width = my_getnbr(buffer);
   else if (l = 1)
     alphabet->height = my_getnbr(buffer);
   else if (l = 2)
     alphabet->col = my_getnbr(buffer);
   printf("%d", alphabet->col);
   l++;
   if (l == 3)
     l = 0;
   return (0);
 }

int	check_tetrimino(char *str, t_piece *alphabet,char *av)
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
	  if ((str[i] != ' ') && str[i] < '0' || str[i] > '9')
	     return (-1);
	  else if ((tab[j++] = get_to_space(i, str, alphabet)) == -1)
	     return (-1);
	}
    }
  fill_struct(tab, alphabet, av);
  return (0);
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
  check_tetrimino(buffer, alphabet, av);
  printf("width%d\n", alphabet->width);
  printf("lenght%d\n", alphabet->height);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 2)
    {
      if (load_info(av[1]) != 0)
	return(-1);
    }
  else
    {
    }
    return(0);
}
