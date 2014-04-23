/*
** backtrack.c for lemin in /home/franck_r/rendu/lem_in
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 22:15:52 2014 Romain Franck
** Last update Tue Mar 25 22:15:52 2014 Romain Franck
*/

#include <stdlib.h>
#include "lemin.h"
#include "nodes.h"

void	backtrack(t_frm *sen, t_nd *room, t_pn *list)
{
  t_pth	*ptr;
  t_pth a;
  int	i;

  a.node = room;
  list->last->next = &a;
  list->last = NULL;
  if (sen->last == room)
    {
      ptr = list->last;
      i = 0;
      while (ptr != list->first)
	{
	  ptr->node->weight = MIN(ptr->node->weight, i++);
	  ptr = ptr->prev;
	}
    }
  i = 0;
  while (room->links[i] != NULL)
    {
      if (!pth_find(list, room->links[i]))
	backtrack(sen, room->links[i], list);
      i++;
    }
  return ;
}

void	move(t_ant *ant)
{
  int	i;
  t_nd	*n;

  i = 0;
  n = ant->node->links[i];
  while (ant->node->links[i] != NULL)
    {
      n = (ant->node->links[i]->weight < n->weight ? ant->node->links[i] : n);
      i++;
    }
  n->full++;
  if (n->full == 1)
    {
      ant->node->full--;
      ant->node = n;
      printf("P%d-%s", ant->number, n->name);
    }
}
