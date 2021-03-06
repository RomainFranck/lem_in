/*
** sort.c for lem_in in /home/galleg_a/lem_in
** 
** Made by Galleg_a
** Login   <galleg_a@epitech.eu>
** 
** Started on  Wed Apr 30 13:45:56 2014 Galleg_a
** Last update Fri May  2 15:49:08 2014 Galleg_a
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemin.h"

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
      if (my_strcmp_no_troll(name, tmp->first) == 0)
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
      if (my_strcmp_no_troll(name, tmp->name) == 0)
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
	  if (my_strcmp_no_troll(r->name, tmp->first) == 0)
	    {
	      if ((r->links[i] = find_node(farm, tmp->second)) == NULL)
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

void	del_link_in_full(t_sln *links, t_lnk *link)
{
  t_lnk	*save;

  save = NULL;
  if (link == links->first)
    {
      save = link->next->next;
      links->first = link->next;
      links->first->prev = 0;
      links->first->next = save;
    }
  else if (link == links->last)
    {
      save = link->prev->prev;
      links->last = link->prev;
      links->last->next = 0;
      links->last->prev = save;
    }
  else
    {
      link->prev->next = link->next;
      link->next->prev = link->prev;
    }
}

t_lnk	*r_maillon(t_lnk *link, t_sln *links, int *next)
{
  t_lnk	*tmp;

  if (links->size > 1)
    {
      tmp = link->next;
      del_link_in_full(links, link);
    }
  else
    {
      printf("No valid link were found\n");
      return (NULL);
    }
  free(link);
  links->size--;
  *next = 0;
  return (tmp);
}

void	del_doublons(t_sln *links)
{
  t_lnk	*tmp1;
  t_lnk	*tmp2;
  int	next;
  int	i;
  int	j;

  i = -1;
  tmp1 = links->first;
  while (++i < links->size)
    {
      j = 0;
      tmp2 = links->first;
      while (j < links->size)
	{
	  next = 1;
	  if (my_strcmp_no_troll(tmp1->link, tmp2->link) == 0 && tmp1 != tmp2)
	    tmp2 = r_maillon(tmp2, links, &next);
	  if (next)
	    {
	      j++;
	      tmp2 = tmp2->next;
	    }
	}
      tmp1 = tmp1->next;
    }
}

int	is_useless(char *link)
{
  int	j;
  int	i;

  i = 0;
  j = 0;
  while (link[i] && link[i] != '-')
    i++;
  i++;
  while (link[j] == '-' && link[i])
    {
      i++;
      j++;
    }
  if (link[j] - link[i] == 0)
    return (1);
  return (0);
}

void	del_useless(t_sln *links)
{
  int	i;
  int	next;
  t_lnk	*tmp;

  i = 0;
  next = 1;
  tmp = links->first;
  while (i < links->size)
    {
      next = 1;
      if (is_useless(tmp->link))
	tmp = r_maillon(tmp, links, &next);
      if (next)
	{
	  i++;
	  tmp = tmp->next;
	}
    }
}

int		init_tree(t_frm *farm, t_sln *links)
{
  unsigned	i;
  int		size;
  t_nd		*tmpn;

  i = 0;
  tmpn = farm->first;
  del_doublons(links);
  del_useless(links);
  while (i < farm->size)
    {
      size = count_nodes(tmpn->name, links);
      if ((tmpn->links = malloc(sizeof(t_nd *) * (size + 1))) == NULL)
	return (EXIT_FAILURE);
      if (fill_node_links(size, tmpn, links, farm) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      tmpn->nb_link = size;
      i++;
      tmpn = tmpn->next;
    }
  return (0);
}
