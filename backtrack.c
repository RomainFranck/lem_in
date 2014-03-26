/*
** backtrack.c for lemin in /home/franck_r/rendu/lem_in
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 22:15:52 2014 Romain Franck
** Last update Tue Mar 25 22:15:52 2014 Romain Franck
*/

#include "lemin.h"
#include "nodes.h"

void	bactrack(t_sen *sen, t_nd *room, t_pn *list)
{
  t_pth	*ptr;
  t_pth a;
  int	i;

  a.nd = room;
  list->last->next = a;
  list->last = NULL;
  if (sen->last == room)
    {
      ptr = list->last;
      i = 0;
      while (ptr != list->first)
	{
	  ptr->nd->dist = MIN(ptr->nd->dist, i++);
	  ptr = ptr->prev;
	}
    }
  i = 0;
  while (room->tab[i] != NULL)
    {
      if (!pth_find(list, room->tab[i]))
	bactrack(room->tab[i]);
      i++;
    }
  return ;
}
