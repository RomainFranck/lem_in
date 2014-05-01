/*
** sort.c for lem_in in /home/galleg_a/lem_in
** 
** Made by Galleg_a
** Login   <galleg_a@epitech.eu>
** 
** Started on  Wed Apr 30 13:45:56 2014 Galleg_a
** Last update Thu May  1 05:39:11 2014 Galleg_a
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
      if (!my_strncmp(name, tmp->link, my_strlen_no_troll(name)))
	{
	  printf("name : %s - link : %s\n", name, tmp->link);
	  size++;
	}
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

t_lnk	*r_maillon(t_lnk *link, t_sln *links, int *next)
{
  t_lnk	*tmp;

  tmp = link->next;
  if (link == links->first)
    {
      links->first = tmp;
      tmp->prev = 0;
      tmp->next = link->next;
    }
  else if (link == links->last)
    {
      tmp->next = 0;
      tmp->prev = link->prev;
      links->last = tmp;
    }
  else
    {
      link->prev->next = link->next;
      link->next->prev = link->prev;
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

  i = 0;
  tmp1 = links->first;
  while (i < links->size)
    {
      j = 0;
      tmp2 = links->first;
      while (j < links->size)
	{
	  next = 1;
	  if (!my_strcmp_no_troll(tmp1->link, tmp2->link) && tmp1 != tmp2)
	    tmp2 = r_maillon(tmp2, links, &next);
	  if (next)
	    {
	      j++;
	      tmp2 = tmp2->next;
	    }
	}
      i++;
      tmp1 = tmp1->next;
    }
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
      del_doublons(links);
      size = count_nodes(tmpn->name, links);
      printf("size : %d\n", size);
      if ((tmpn->links = malloc(sizeof(t_nd *) * (size + 1))) == NULL)
	return (EXIT_FAILURE);
      if (fill_node_links(size, tmpn, links, farm) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      i++;
      tmpn = tmpn->next;
    }
  return (0);
}
