/*
** main.c for lemin in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 14:22:50 2014 Romain Franck
** Last update Tue Mar 25 22:38:03 2014 Galleg_a
*/

#include <stdio.h>
#include "nodes.h"
#include "lemin.h"

void	comment(t_sen *farm, char *line)
{
  char	*line;

  if (my_strncmp(line, "##start", 7))
    {
      if ((line = getnextline) != 0)
	add_node_to_list(farm);
      //farm first = cet elem
      free(line);
    }
  else if (my_strncmp(line, "##end", 5))
    {
      if ((line = getnextline) != 0)
	add_node_to_list(farm);
      //farm last = cet elem
      free(line);
    }
}

int	create_node_list(t_sen *farm)
{
  int	kill;
  char	*line;

  kill = 1;
  if ((line = getnextline(1)) != 0)
    farm->ants = atoi(line); //GETNBR
  free(line);
  while (kill && (line = getnextline(1)) != 0)
    {
      if (line[0] == '#')
	comment(farm, line);
      else
	{
	  if (/*ligne ne contient pas 3 elements*/)
	    kill = 0;
	  else
	    add_node_to_list(farm);
	}
      free(line);
    }
  while ((line = getnextline(1)) != 0)
    free(line); //gestion des liaisons
  return (0);
}

int	main()
{
  t_sen	farm;

  create_node_list(&farm);
}
