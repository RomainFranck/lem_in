/*
** nodes.h for lem_in in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 11:09:02 2014 Romain Franck
** Last update Tue Mar 25 22:37:45 2014 Galleg_a
*/

#ifndef NODES_H_
# define NODES_H_

typedef struct	s_node
{
  struct s_node	*prev;
  char		*name;
  //int		dist;
  char		full;
  struct s_node	*links;
  struct s_node	*next;
} t_nd;

typedef struct	s_farm_sen
{
  t_nd		*enter;
  t_nd		*exit;
  int		size;
  int		ants;
} t_frm;

typedef struct	s_path
{
  struct s_path	prev;
  t_nd		*node;
  struct s_path	next;
} t_pth;

typedef struct	s_path_sen
{
  t_pth		*first;
  t_pth		*last;
  int		size;
} t_pn;

/*
** Définir l'emplacement de la fourmi selon le node ou la fourmi ?
*/

typedef struct	s_ant
{
  int		number;
  t_nd		*node;
  struct s_ant	*next;
} t_ant;

#endif
