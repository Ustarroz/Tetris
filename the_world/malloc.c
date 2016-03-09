/*
** malloc.c for tetris in /home/voyevoda/rendu/systeme_unix/PSU_2015bstetris
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Thu Mar  3 15:54:35 2016 Voyevoda
** Last update Tue Mar  8 11:36:08 2016 Voyevoda
*/
#include "../include/tetris.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

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

char	*my_strcat(char*av, char *av2)
{
  
}

int		files()
{
  DIR		*dir;
  struct dirent *file;
  int		files;
    
  files = 0;
  if ((dir = opendir("./tetriminos")) == NULL)
    {
      printf("no tetriminos available here");
      return (-1);
    }
  else
    {
      while ((file = readdir(dir)) != NULL)
	{
	  if (my_strcmp_tetrimino(file->d_name) == 0)
	    {
	      files++;
	      load_info("./tetriminos/"file->d_name);
	    }
	}
    }
  return (0);
}

void	malloc_piece(t_piece *alphabet)
{
  int	i;
  
  i = -1;
  alphabet->shape = malloc(sizeof(char *) * (alphabet->height));
  while (++i < alphabet->height)
    {
      alphabet->shape[i] = malloc(sizeof(char) * alphabet->width + 1);
      alphabet->shape[i][alphabet->width] = '\0';
    }
}
