/*
** sort.c for lem_in in /home/galleg_a/lem_in
** 
** Made by Galleg_a
** Login   <galleg_a@epitech.eu>
** 
** Started on  Wed Apr 30 13:45:56 2014 Galleg_a
** Last update Thu May  1 02:18:02 2014 Galleg_a
*/

#include <stdlib.h>
#include "lemin.h"

#include <stdio.h>

int    	count_nodes(char *name, t_sln *links)
{
  int	i;
  int	size;
  t_lnk	*tmp;

  i = 0;
  size = 0;
  tmp = links->first;
  while (i < links->size)
    {
      if (!my_strncmp(name, tmp->link, my_strlen_no_troll(name)))
	size++;
      tmp = tmp->next;
      i++;
    }
  return (size);
}

t_nd		*find_node(t_frm *farm, char *name)
{
  unsigned	i;
  t_nd		*tmp;

  i = 0;
  tmp = farm->first;
  while (i < farm->size)
    {
      if (!my_strncmp(name, tmp->name, my_strlen_no_troll(tmp->name)))
	return (tmp);
      tmp = tmp->next;
      i++;
    }
  return (NULL);
}

int	fill_node_links(int size, t_nd *r, t_sln *links, t_frm *farm)
{
  int	i;
  int	j;
  t_lnk	*tmp;

  i = 0;
  while (i < size)
    {
      j = 0;
      tmp = links->first;
      while (j < links->size)
	{
	  if (!my_strncmp(r->name, tmp->link, my_strlen_no_troll(r->name)))
	    {
	      if ((r->links[i] = find_node(farm, tmp->link)) == NULL)
		return (EXIT_FAILURE);
	      i++;
	    }
	  tmp = tmp->next;
	  j++;
	}
    }
  r->links[i] = NULL;
  return (0);
}

int		init_tree(t_frm *farm, t_sln *links)
{
  unsigned	i;
  int		size;
  t_nd		*tmpn;

  i = 0;
  tmpn = farm->first;
  while (i < farm->size)
    {
      size = count_nodes(tmpn->name, links);
      if ((tmpn->links = malloc(sizeof(t_nd) * (size + 1))) == NULL)
	return (EXIT_FAILURE);
      if (fill_node_links(size, tmpn, links, farm) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      tmpn = tmpn->next;
      i++;
    }
  return (0);
}
