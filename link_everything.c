/*
** link_everything.c for lem_in in /home/galleg_a/lem_in
** 
** Made by Galleg_a
** Login   <galleg_a@epitech.eu>
** 
** Started on  Thu May  1 03:04:44 2014 Galleg_a
** Last update Sat May  3 07:28:25 2014 Galleg_a
*/

#include <stdlib.h>
#include <stdio.h>
#include "lemin.h"

int	check_already_exist(t_nd *node, t_lnk *link)
{
  int	i;

  i = 0;
  while (i < node->nb_link)
    {
      if (my_strcmp_no_troll(link->first, node->links[i]->name) == 0)
	return (1);
      i++;
    }
  return (0);
}

int	count_other_nodes(char *name, t_nd *node, t_sln *links)
{
  int	i;
  t_lnk	*link;
  int	size;

  i = 0;
  size = 0;
  link = links->first;
  while (i < links->size)
    {
      if (my_strcmp_no_troll(name, link->second) == 0 &&
	  !check_already_exist(node, link))
	size++;
      link = link->next;
      i++;
    }
  return (size);
}

t_nd	**fill_new_links(t_nd *node, t_sln *links, t_nd **new_links, t_frm *farm)
{
  t_lnk	*tmp;
  int	j;
  int	i;

  i = 0;
  tmp = links->first;
  while (i < node->nb_link)
    {
      new_links[i] = node->links[i];
      i++;
    }
  j = -1;
  while (++j < links->size)
    {
      if (my_strcmp_no_troll(node->name, tmp->second) == 0 &&
	  !check_already_exist(node, tmp))
	{
	  if ((new_links[i] = find_node(farm, tmp->first)) == NULL)
	    return (NULL);
	  i++;
	}
      tmp = tmp->next;
    }
  new_links[i] = NULL;
  return (new_links);
}

int		link_everything(t_frm *farm, t_sln *links)
{
  unsigned	i;
  int		size;
  t_nd		*tmp;
  t_nd		**new_links;

  i = 0;
  size = 0;
  tmp = farm->first;
  while (i < farm->size)
    {
      size = count_other_nodes(tmp->name, tmp, links);
      if ((new_links = malloc(sizeof(t_nd *) *
			      (size + tmp->nb_link + 1))) == NULL)
	return (EXIT_FAILURE);
      if ((new_links = fill_new_links(tmp, links, new_links, farm)) == NULL)
	return (EXIT_FAILURE);
      tmp->links = new_links;
      tmp->nb_link += size;
      i++;
      tmp = tmp->next;
    }
  return (0);
}
