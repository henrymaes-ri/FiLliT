/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaes-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 19:49:00 by hemaes-r          #+#    #+#             */
/*   Updated: 2018/05/27 19:49:24 by hemaes-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define TAB tet->table[i]
#define NEXT tet->next

int		solve_it(t_tetlst *tet, t_map *map)
{
	int x;
	int y;

	if (tet == NULL)
		return (1);
	y = 0;
	while (y <= map->size - tet->height)
	{
		x = 0;
		while (x <= map->size - tet->width)
		{
			if (!check_it(tet, map, x, y))
			{
				place_it(tet, map, x, y);
				if (solve_it(NEXT, map))
					return (1);
				else
					remove_it(tet, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	remove_it(t_tetlst *tet, t_map *map, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
		map->table[TAB.y + y][TAB.x + x] = '.';
}

void	place_it(t_tetlst *tet, t_map *map, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
		map->table[TAB.y + y][TAB.x + x] = tet->order;
}

int		check_it(t_tetlst *tet, t_map *map, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (map->table[TAB.y + y][TAB.x + x] != '.')
			return (1);
	}
	return (0);
}

t_map	*solve(t_tetlst *list)
{
	t_tetlst	*tet;
	t_map		*map;
	int			size;

	tet = list;
	size = map_init(ft_lstsize(list));
	map = create_map(size);
	while (!solve_it(tet, map))
	{
		free_map(map);
		size++;
		map = create_map(size);
		tet = list;
	}
	return (map);
}
