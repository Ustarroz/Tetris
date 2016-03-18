/*
** malloc.c for tetris in /home/voyevoda/rendu/systeme_unix/PSU_2015bstetris
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Thu Mar  3 15:54:35 2016 Voyevoda
** Last update Fri Mar 18 12:50:14 2016 Voyevoda
*/

#include "../include/tetris.h"

int	my_strcmp_tetrimino(char *file)
{
  int	i;
  char	*test;
  int	k;

  test = ".tetrimino";
  i = my_strlen(file);
  k = my_strlen(test);
  while (k != 0 && i != 0)
    {
      if (file[i] == test[k])
	{
	  i--;
	  k--;
	}
      else
	return (-1);
    }
  if (k != 0)
    return (- 1);
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

int		files(t_piece **list)
{
  DIR		*dir;
  struct dirent *file;
  int		files;
  char		*name;

  files = 0;
  if ((dir = opendir("./tetriminos")) == NULL)
    {
      my_putstr_error(PATH_ERR_MSG);
      return (-1);
    }
  else
    while ((file = readdir(dir)) != NULL)
      if (my_strcmp_tetrimino(file->d_name) == 0)
	{
	  if ((name = my_strcat("./tetriminos/", file->d_name)) == NULL)
	    return (- 1);
	  files++;
	  if ((load_info(name, list)) == - 1)
	    return (- 1);
	}
  closedir(dir);
  if (files == 0)
    my_putstr_error(TET_ERR_MSG);
  return ((files == 0) ? - 1 : files);
}

int	malloc_piece(t_piece *alphabet)
{
  int	i;

  i = - 1;
  if ((alphabet->shape = malloc(sizeof(char *) * (alphabet->height))) == NULL)
    {
      my_putstr_error(MALLOC_ERR_MSG);
      return (- 1);
    }
  while (++i < alphabet->height)
    {
      if ((alphabet->shape[i] =
	   malloc(sizeof(char) * alphabet->width + 1)) == NULL)
	{
	  my_putstr_error(MALLOC_ERR_MSG);
	  return (- 1);
	}
      alphabet->shape[i][alphabet->width] = '\0';
    }
  return (0);
}

void	free_tab(t_piece *tmp2)
{
  int	j;

  j = -1;
  while (++j < tmp2->height)
    free(tmp2->shape[j]);
  free(tmp2->shape);
}
