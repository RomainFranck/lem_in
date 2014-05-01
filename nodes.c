/*
** nodes.c for lemin in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 12:21:39 2014 Romain Franck
** Last update Thu May  1 15:41:58 2014 root
*/

#include <stdlib.h>
#include "lemin.h"

void	in_empty_link_list(t_sln *links, t_lnk *maillon, char *line)
{
  links->first = maillon;
  links->last = maillon;
  links->size += 1;
  maillon->link = my_strdup_no_troll(line);
  maillon->next = 0;
  maillon->prev = 0;
}

void	in_link_list(t_sln *links, t_lnk *maillon, char *line)
{
  maillon->prev = links->last;
  maillon->next = 0;
  maillon->link = my_strdup_no_troll(line);
  links->last->next = maillon;
  links->last = maillon;
  links->size += 1;
}

t_lnk	*add_link_to_list(t_sln *links, char *line)
{
  t_lnk	*maillon;

  if ((maillon = malloc(sizeof(t_nd))) == 0)
    return (NULL);
  if (links->size == 0)
    in_empty_link_list(links, maillon, line);
  else
    in_link_list(links, maillon, line);
  return (maillon);
}

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

char	*get_name(char *line)
{
  char	*name;
  int	size;
  int	i;

  i = 0;
  while (line[i] && line[i] != ' ')
    i++;
  size = i;
  i = 0;
  if ((name = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while (line[i] && line[i] != ' ')
    {
      name[i] = line[i];
      i++;
    }
  name[i] = 0;
  return (name);
}

void	put_in_empty_node_list(t_frm *farm, t_nd *maillon, char *line)
{
  farm->first = maillon;
  farm->last = maillon;
  farm->size += 1;
  maillon->name = get_name(line);
  maillon->weight = 0;
  maillon->full = 0;
  maillon->next = 0;
  maillon->prev = 0;
}

void	put_in_node_list(t_frm *farm, t_nd *maillon, char *line)
{
  maillon->name = get_name(line);
  maillon->prev = farm->last;
  maillon->next = 0;
  maillon->weight = 0;
  maillon->full = 0;
  farm->last->next = maillon;
  farm->last = maillon;
  farm->size += 1;
}

t_nd	*nd_find(t_nd *f, char *name)
{
  t_nd	*ptr;

  ptr = f;
  while (my_strcmp(ptr->name, name) == 0 && ptr->next != NULL)
    ptr = ptr->next;
  return (ptr);
}

int	pth_find(t_pn *list, t_nd *room)
{
  t_pth	*ptr;

  ptr = list->first;
  while (ptr != list->last)
    {
      if (ptr->node == room)
	return (1);
      ptr = ptr->next;
    }
  return (0);
}
