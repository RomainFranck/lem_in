/*
** nodes.h for lem_in in /home/franck_r/rendu/lemin
**
** Made by Romain Franck
** Login   <franck_r@epitech.net>
**
** Started on  Tue Mar 25 11:09:02 2014 Romain Franck
** Last update Thu May  1 02:46:54 2014 root
*/

#ifndef NODES_H_
# define NODES_H_

# define MIN(x, y)	(x < y ? x == -1 ? y : x : y == -1 ? x : y)
# define WEIGHT(x, y)	(x < y ? x == 0 ? y : x : y == 0 ? x : y)

typedef struct	s_node
{
  struct s_node	*prev;
  char		*name;
  int		weight;
  int		full;
  struct s_node	**links;
  struct s_node	*next;
} t_nd;

typedef struct	s_farm_sen
{
  t_nd		*start;
  t_nd		*exit;
  t_nd		*first;
  t_nd		*last;
  unsigned	size;
  int		ants;
} t_frm;

typedef struct	s_ant
{
  int		number;
  t_nd		*node;
  struct s_ant	*next;
} t_ant;

typedef struct	s_path
{
  struct s_path	*prev;
  t_nd		*node;
  struct s_path	*next;
} t_pth;

typedef struct	s_psen
{
  t_pth	*first;
  t_pth	*last;
} t_pn;

typedef struct		s_lnkstr
{
  struct s_lnkstr	*prev;
  struct s_lnkstr	*next;
  char			*link;
} t_lnk;

typedef struct	s_lnksen
{
  t_lnk		*first;
  t_lnk		*last;
  int		size;
} t_sln;

#endif
