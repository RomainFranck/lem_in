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
	bactrack(room->links[i]);
      i++;
    }
  return ;
}
