/*
** main.c for tetris in /home/voyevoda/rendu/systeme_unix/PSU_2015bstetris
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Tue Feb 23 16:59:20 2016 Voyevoda
** Last update Tue Mar  8 14:15:58 2016 Voyevoda
*/
#include "../include/tetris.h"

int	fill_piece(t_piece *alphabet, char *buffer, int line)
{
  int	i;
  int	k;

  k = 0;
  i = -1;
  while (buffer[++i] != '\0')
    {
      if (buffer[i] != ' ' && buffer[i] != '*')
	return (-1);
      if (i > alphabet->width && buffer[i] != ' ')
	return (-1);
    }
  i = -1;
  while (++i != alphabet->width)
    {
      if (buffer[i] == '*')
	k++;
      if (i == alphabet->width && k == 0)
	return (-1);
      alphabet->shape[line][i] = buffer[i];
    }
  return (0);
}

int		fill_struct(t_piece *alphabet, int fd)
{
  char          *buffer;
  int		k;
  
  k = -1;
  while ((buffer = get_next_line(fd)) != NULL && ++k < alphabet->height)
    {
      if ((fill_piece(alphabet, buffer, k)) == -1)
	{
	  printf("%s", buffer);
	  printf("OPEN ERROR\n");
	  return (-1);
	}
      if (buffer == NULL && (k < alphabet->height || k > alphabet->height))
	return (-1);
    }
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
   malloc_piece(alphabet);
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
  check_tetrimino(buffer, alphabet, fd);
  files(alphabet);
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
      printf("aurevoir");
    }
  return(0);
}
