/*
** main_bootstrap.c for bootstrap in /home/voyevoda/rendu/systeme_unix/PSU_2015_tetris
**
** Made by Voyevoda
** Login   <voyevoda@epitech.net>
**
** Started on  Thu Feb 25 19:20:09 2016 Voyevoda
** Last update Thu Feb 25 19:51:16 2016 Voyevoda
*/

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "./include/get_next_line.h"

int	main(int ac, char **av)
{
  int	fd;


  fd = open(av[1], O_RDONLY);
  read(fd, )
}
