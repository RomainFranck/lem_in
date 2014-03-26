#ifndef LEMIN_H_
# define LEMIN_H_

#include "nodes.h"

/*-------------[getnbr.c]------------*/
int	is_alphaz(char c);
int	my_getnbr_aux(int nbr, char *str, int minus);
int	my_getnbr(char *str);
/*-----------------------------------*/

/*-------------[getnextline.c]------------*/
char	*scat(char *a, char b);
char	*getnextline(int fd);
/*----------------------------------------*/

/*-------------[main.c]------------*/
void	comment(t_frm *farm, char *line);
int	create_node_list(t_frm *farm);
int	main();
/*---------------------------------*/

/*-------------[nodes.c]------------*/
t_nd	*add_node_to_list(t_frm *farm, int type, char *line);
void	put_in_empty_node_list(t_frm *farm, t_nd *maillon, char *line);
void	put_in_node_list(t_frm *farm, t_nd *maillon, char *line);
t_nd	*nd_find(t_nd *f, char *name);
/*t_nd	*nd_find_tab(t_tn *f, char *name);*/
/*----------------------------------*/

/*-------------[str.c]------------*/
int	my_strcmp(char *a, char *b);
int	my_strlen(char *s, int i);
int	my_strncmp(const char *s1, const char *s2, unsigned n);
char	*my_strdup(char *s, int i);
/*--------------------------------*/

#endif
