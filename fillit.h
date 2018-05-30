/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaes-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:44:22 by hemaes-r          #+#    #+#             */
/*   Updated: 2018/05/21 15:44:23 by hemaes-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TET 21
# include <stddef.h>

typedef struct		s_map
{
	int				size;
	char			**table;
}					t_map;

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tetlst
{
	char			order;
	int				width;
	int				height;
	t_point			table[4];
	struct s_tetlst	*next;
}					t_tetlst;

int					main(int argc, char **argv);
int					solve_it(t_tetlst *tet, t_map *map);
int					check_it(t_tetlst *tet, t_map *map, int x, int y);
int					valid_move(char *buf);
int					validate_tet(char *buf, int bytes);
int					map_init(int tets);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				free_map(t_map *map);
void				ft_bzero(void *s, size_t size);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char *str, int fd);
void				*ft_memalloc(size_t size);
void				ft_putmap(t_map *map);
void				add_width_height(t_tetlst *list, t_tetlst *tet);
void				trim_to_shape(t_tetlst *list, t_tetlst *tet);
void				fillit_puterror(const char *prog);
void				remove_it(t_tetlst *tet, t_map *map, int x, int y);
void				place_it(t_tetlst *tet, t_map *map, int x, int y);
size_t				ft_lstsize(t_tetlst *begin_list);
size_t				ft_strlen(const char *s);
t_tetlst			*read_tet(int fd, char *buf);
t_tetlst			*create_tet(void);
t_tetlst			*free_list(t_tetlst *list);
t_tetlst			*store_data(t_tetlst *tet, char *buf, char order);
t_map				*create_map(int size);
t_map				*solve(t_tetlst *list);

#endif
