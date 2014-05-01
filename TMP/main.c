/*
** main.c for lemin in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 14:22:50 2014 Romain Franck
** Last update Thu May  1 02:21:10 2014 Galleg_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemin.h"

int	create_tree(t_frm *farm, t_sln *links)
{
  if (init_tree(farm, links) == EXIT_FAILURE)
    {
      printf("Failed to create tree\n");
      return (EXIT_FAILURE);
    }
  epur_tree(farm);
  return (0);
}

int	is_alphanum(char c)
{
  if ((c >= '0' && c <= '9') || is_alphaz(c))
    return (1);
  return (0);
}

int	valid_link_input(char *line)
{
  int	i;

  i = -1;
  while (is_alphanum(line[++i]) && line[i]);
  if (line[i] == '-')
    {
      while (is_alphanum(line[++i]) && line[i]);
      if (!line[i])
	return (1);
    }
  printf("Invalid link input\n");
  return (0);
}

int	valid_node_input(char *line)
{
  int	i;
  int	space;

  i = -1;
  space ^= space;
  while (line[++i] && (is_alphanum(line[i]) || line[i] == ' '))
    if (line[i] == ' ')
      space++;
  return ((space == 2) ? 1 : 0);
}

void	manage_link(char *line, t_sln *links, int *kill)
{
  if (line[0] == '#')
    {
      free(line);
      line = getnextline(1);
    }
  if (!valid_link_input(line))
    *kill = 0;
  else
    add_link_to_list(links, line);
  free(line);
}

void	add_valid_node(t_frm *farm, char *line, int *kill, int type)
{
  if (valid_node_input(line))
    add_node_to_list(farm, type, line);
  else if (valid_link_input(line))
    *kill = 0;
  else
    {
      printf("Invalid room definition : (usage)-->[NAME X_POS Y_POS]\n"); /* my_printf */
      *kill = 0;
    }
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

void	manage_rooms(char *line, int *kill, t_frm *farm)
{
  if (line[0] == '#')
    comment(farm, line, kill);
  else
    add_valid_node(farm, line, kill, 0);
  if (*kill > 0)
    free(line);
}

int	create_node_list(t_frm *farm, t_sln *links)
{
  char	*line;
  int 	kill;

  kill = 1;
  if ((line = getnextline(1)) != 0)
    if ((farm->ants = my_getnbr(line)) < 1)
      return (printf("Ant number must be > 0 (input : %d)\n", farm->ants));
  free(line);
  while (kill > 0 && (line = getnextline(1)) != 0)
    manage_rooms(line, &kill, farm);
  if (valid_link_input(line))
    {
      add_link_to_list(links, line);
      free(line);
    }
  kill = 1;
  while (kill && (line = getnextline(1)) != 0)
    manage_link(line, links, &kill);
  return (0);
}

int	main()
{
  t_sln	links;
  t_frm	farm;

  /* memset */
  farm.start = 0;
  farm.exit = 0;
  farm.last = 0;
  farm.first = 0;
  farm.size = 0;
  farm.ants = 0;
  /* ------ */
  links.size = 0;
  if (create_node_list(&farm, &links) != 0)
    return (EXIT_FAILURE);
  if (create_tree(&farm, &links) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (0);
}