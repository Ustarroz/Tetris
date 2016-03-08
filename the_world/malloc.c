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

int		files()
{
  DIR		*dir;
  struct dirent *file;
  int		i;

  i = 0;
  if ((dir = opendir("./tetriminos")) == NULL)
    {
      printf("no tetriminos available here");
      return (-1);
    }
  else
    {
      file = readdir(dir);
      file->d_name();
      return (0);
    }
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
