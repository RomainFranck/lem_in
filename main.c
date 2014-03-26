/*
** main.c for lemin in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 14:22:50 2014 Romain Franck
** Last update Wed Mar 26 02:58:32 2014 Galleg_a
*/

#include <stdlib.h>
#include "lemin.h"

int	valid_node_input(char *line)
{
  int	i;
  int	space;

  i = -1;
  space ^= space;
  while (line[++i])
    if (line[i] == ' ')
      space++;
  return ((space == 2) ? 1 : 0);
}

void	add_valid_node(t_frm *farm, char *line, int *kill, int type)
{
  if (valid_node_input(line))
    add_node_to_list(farm, type, line);
  else
    *kill = 0;
}

void	comment(t_frm *farm, char *line, int *kill)
{
  char	*data;

  if (my_strncmp(line, "##start", 7))
    {
      free(line);
      if ((data = getnextline(1)) != 0)
	add_valid_node(farm, data, kill, 1);
      free(data);
    }
  else if (my_strncmp(line, "##end", 5))
    {
      free(line);
      if ((data = getnextline(1)) != 0)
	add_valid_node(farm, data, kill, 2);
      free(data);
    }
}

int	create_node_list(t_frm *farm)
{
  int	kill;
  char	*line;

  kill = 1;
  if ((line = getnextline(1)) != 0)
    farm->ants = my_getnbr(line);
  free(line);
  while (kill && (line = getnextline(1)) != 0)
    {
      if (line[0] == '#')
	comment(farm, line, &kill);
      else
	add_valid_node(farm, line, &kill, 0);
      free(line);
    }
  while (my_strcmp(line, "")/*(line = getnextline(1)) != 0*/)
    free(line); /*gestion des liaisons*/
  return (0);
}

int	main()
{
  t_frm	farm;

  /* memset */
  farm.start = 0;
  farm.exit = 0;
  farm.last = 0;
  farm.first = 0;
  farm.size = 0;
  farm.ants = 0;
  /*--------*/
  create_node_list(&farm);
  return (0);
}
