/*
** malloc.c for tetris in /home/voyevoda/rendu/systeme_unix/PSU_2015bstetris
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Thu Mar  3 15:54:35 2016 Voyevoda
** Last update Sat Mar 12 14:41:07 2016 Voyevoda
*/
#include "../include/tetris.h"

int	my_strcmp_tetrimino(char *file)
{
  int	i;
  char	*test;
  int	k;

  k = 10;
  test = ".tetrimino";
  i = my_strlen(file);
  while (i != 0)
    {
      if (file[i] == test[k])
	{
	  i--;
	  k--;
	  if (file[i] != test[k])
	    return (-1);
	}
    }
  return (0);
}

char	*my_strcat(char *av, char *av2)
{
  int	k;
  int	i;
  int	size;
  char	*name;

  k = - 1;
  i = -1;
  size = my_strlen(av) + my_strlen(av2);
  if ((name = malloc(size + 1)) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (NULL);
    }
  while (++i != size)
    if (i < my_strlen(av))
      name[i] = av[i];
    else
      name[i] = av2[++k];
  name[i] = '\0';
  return (name);
}

int		files(t_piece *list)
{
  DIR		*dir;
  struct dirent *file;
  int		files;
  char		*name;

  files = 0;
  if ((dir = opendir("./tetriminos")) == NULL)
    {
      printf("no tetriminos available here");
      return (-1);
    }
  else
    while ((file = readdir(dir)) != NULL)
      if (my_strcmp_tetrimino(file->d_name) == 0)
	{
	  if ((name = my_strcat("./tetrimino", file->d_name)) == NULL)
	    return (- 1);
	  files++;
	  if ((load_info(name, list)) == 0)
	    return (0);
	}
  return (files);
}

int	malloc_piece(t_piece *alphabet)
{
  int	i;

  i = -1;
  if ((alphabet->shape = malloc(sizeof(char *) * (alphabet->height))) == NULL)
    return (-1);
  while (++i < alphabet->height)
    {
      if ((alphabet->shape[i] =
	   malloc(sizeof(char) * alphabet->width + 1)) == NULL)
	return (-1);
      alphabet->shape[i][alphabet->width] = '\0';
    }
  return (0);
}
