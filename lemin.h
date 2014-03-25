/*
** lemin.h for lemin in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 14:23:43 2014 Romain Franck
** Last update Tue Mar 25 14:23:43 2014 Romain Franck
*/

#ifndef LEMIN_H_
#define LEMIN_H_

char	*my_strdup(char *, int);
int	my_strlen(char *, int);
int	my_strcmp(char *, char *);
t_nd	*nd_init(char *, char);
t_nd	*nd_add(t_nd *, char *, char);
t_nd	*nd_find(t_nd *, char *);
t_nd	*tn_link(t_nd *, char *, char *);
t_nd	*tn_add(t_nd *, char *);

#endif
