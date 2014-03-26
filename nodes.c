/*
** nodes.c for lemin in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 12:21:39 2014 Romain Franck
** Last update Wed Mar 26 02:10:49 2014 root
*/

#include <stdlib.h>
#include "lemin.h"

t_nd	*add_node_to_list(t_frm *farm, int type, char *line)
{
  t_nd	*maillon;

  if ((maillon = malloc(sizeof(t_nd))) == 0)
    return (NULL);
  if (type == 1)
    farm->start = maillon;
  else if (type == 2)
    farm->exit = maillon;
  if (farm->size == 0)
    put_in_empty_node_list(farm, maillon, line);
  else
    put_in_node_list(farm, maillon, line);
  return (maillon);
}

void	put_in_empty_node_list(t_frm *farm, t_nd *maillon, char *line)
{
  (void) line;
  maillon->prev = maillon;
  maillon->next = maillon;
  farm->first = maillon;
  farm->last = maillon;
  farm->size += 1;
  maillon->next = 0;
  maillon->prev = 0;
}

void	put_in_node_list(t_frm *farm, t_nd *maillon, char *line)
{
  (void) line;
  maillon->prev = farm->last;
  maillon->next = farm->first;
  farm->last->next = maillon;
  farm->last = maillon;
  farm->size += 1;
  farm->first->prev = farm->last;
}

t_nd	*nd_find(t_nd *f, char *name)
{
  t_nd	*ptr;

  ptr = f;
  while (my_strcmp(ptr->name, name) == 0 && ptr->next != NULL)
    ptr = ptr->next;
  return (ptr);
}
/* ne compile pas unknown type t_tn *
t_nd	*nd_find_tab(t_tn *f, char *name)
{
  int	i;

  i = 0;
  while (my_strcmp(f[i]->name, name) == 0 && f[i + 1] != NULL)
    i++;
  return (f[i]);
}
*/
