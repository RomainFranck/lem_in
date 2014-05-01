/*
** link_everything.c for lem_in in /home/galleg_a/lem_in
** 
** Made by Galleg_a
** Login   <galleg_a@epitech.eu>
** 
** Started on  Thu May  1 03:04:44 2014 Galleg_a
** Last update Thu May  1 16:59:58 2014 Galleg_a
*/

#include <stdio.h>
#include "lemin.h"
/*
int	get_beginning(char *link)
{
  int	i;

  i = 0;
  while (link[i] && link[i] != '-')
    i++;
  i++;
  return (i);
}

int	check_already_exist(t_lnk *link, char *name, int j)
{
  return (0);
}

int	get_real_size(char *name, t_sln *links, t_frm *farm)
{
  int	i;
  int	j;
  int	size;
  t_lnk	*tmp;

  i = 0;
  size = 0;
  tmp = links->first;
  while (i < links->size)
    {
      j = get_beginning(tmp->link);
      if (!my_strcmp_no_troll(name, &(tmp->link[j])))
	{
	  if (!check_already_exist(tmp, name, j, farm))
	    size++;
	  printf("name : %s -> %s\n", name, &(tmp->link[j]));
	}
      i++;
      tmp = tmp->next;
    }
  return (0);
}
*/
int		link_everything(t_frm *farm, t_sln *links)
{
  unsigned	i;
  int		size;
  t_nd		*tmp;
  t_nd		**new_links;

  (void) size;
  (void) new_links;
  i = 0;
  size = 0;
  tmp = farm->first;
  while (i < farm->size)
    {
      size = get_real_size(tmp->name, links, farm);
      i++;
      tmp = tmp->next;
    }
  return (0);
}
