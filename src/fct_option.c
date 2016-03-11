/*
** fct_option.c for PSU_2015_tetris in /home/puilla_e/Semestre2/psu/
** 
** Made by edouard puillandre
** Login   <puilla_e@epitech.net>
** 
** Started on  Thu Mar  3 14:11:01 2016 edouard puillandre
** Last update Thu Mar 10 16:26:24 2016 edouard puillandre
*/

#include "tetris.h"

int	set_kr(t_tetris *tetris, int *i, char **argv, int argc)
{
#ifdef DEBUG
  my_printf("kr\n");
#endif
  *i = *i + 1;
  if (*i >= argc)
    {
      my_putstr_error(ARG_ERR_MSG);
      my_putnbr_error(*i - 1, true);
      return (- 1);
    }
  free(tetris->cmd[ID_KR].key);
  tetris->cmd[ID_KR].key = my_strdup(argv[*i]);
  return (0);
}

int	set_help(t_tetris *tetris, int *i, char **argv, int argc)
{
  (void) tetris;
  (void) i;
  (void) argc;
  my_printf("Usage: ");
  my_printf(argv[0]);
  my_printf(" [options]\n");
  my_printf("Options:\n");
  my_printf("  --help\t\tDisplay this help\n");
  my_printf("  -l --level={num}\tStart Tetris at level num\n");
  my_printf("  -kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
  my_printf("  -kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
  my_printf("  -kt --key-turn={K}\tTurn tetrimino with key K\n");
  my_printf("  -kd --key-drop={K}\tSet default DROP on key K\n");
  my_printf("  -kq --key-quit={K}\tQuit program when press key K\n");
  my_printf("  -kp --key-pause={K}\t");
  my_printf("Pause and restart game when press key K\n");
  my_printf("  --map-size={row,col}\tSet gamesize at row, col\n");
  my_printf("  -w --without-next\tHide next tetrimino\n");
  my_printf("  -d --debug\t\tDebug mode\n");
  return (1);
}

void	init_tab_key(t_opt *opt)
{
  opt[ID_KL].eq = "--key-left=";
  opt[ID_KL].str = "-kl";
  opt[ID_KL].fct = &(set_kl);
  opt[ID_KL].fct_eq = &(set_kl_eq);
  opt[ID_KR].eq = "--key-right=";
  opt[ID_KR].str = "-kr";
  opt[ID_KR].fct = &(set_kr);
  opt[ID_KR].fct_eq = &(set_kr_eq);
  opt[ID_KT].eq = "--key-turn=";
  opt[ID_KT].str = "-kt";
  opt[ID_KT].fct = &(set_kt);
  opt[ID_KT].fct_eq = &(set_kt_eq);
  opt[ID_KD].eq = "--key-drop=";
  opt[ID_KD].str = "-kd";
  opt[ID_KD].fct = &(set_kd);
  opt[ID_KD].fct_eq = &(set_kd_eq);
  opt[ID_KQ].eq = "--key-quit=";
  opt[ID_KQ].str = "-kq";
  opt[ID_KQ].fct = &(set_kq);
  opt[ID_KQ].fct_eq = &(set_kq_eq);
  opt[ID_KP].eq = "--key-pause=";
  opt[ID_KP].str = "-kp";
  opt[ID_KP].fct = &(set_kp);
  opt[ID_KP].fct_eq = &(set_kp_eq);
}

void	init_tab_opt(t_opt *opt, int argc)
{
  int	i;

  opt[ID_HELP].str = "--help";
  opt[ID_HELP].eq = NULL;
  opt[ID_HELP].fct = &(set_help);
  opt[ID_LVL].eq = "--level=";
  opt[ID_LVL].str = "-l";
  opt[ID_LVL].fct = &(set_lvl);
  opt[ID_LVL].fct_eq = &(set_lvl_eq);
  opt[ID_MAP].eq = "--map-size=";
  opt[ID_MAP].str = "-m";
  opt[ID_MAP].fct = &(set_map);
  opt[ID_MAP].fct_eq = &(set_map_eq);
  opt[ID_W].eq = "--without-next";
  opt[ID_W].str = "-w";
  opt[ID_W].fct = &(set_w);
  opt[ID_W].fct_eq = &(set_w_eq);
  opt[ID_D].eq = "--debug";
  opt[ID_D].str = "-d";
  opt[ID_D].fct = &(set_debug);
  opt[ID_D].fct_eq = &(set_debug_eq);
  i = - 1;
  while (++i < OPT_LEN)
    opt[i].arg = argc;
  init_tab_key(opt);
}
