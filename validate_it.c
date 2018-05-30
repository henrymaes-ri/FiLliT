/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaes-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:14:01 by hemaes-r          #+#    #+#             */
/*   Updated: 2018/05/28 18:14:02 by hemaes-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

int		valid_move(char *buf)
{
	int i;
	int move;

	i = -1;
	move = 0;
	while (++i < 20)
	{
		if (buf[i] == '#')
		{
			(buf[i + 1] == '#' && i % 5 < 3) ? move++ : move;
			(buf[i - 1] == '#' && i % 5 > 0) ? move++ : move;
			(buf[i + 5] == '#' && i / 5 < 3) ? move++ : move;
			(buf[i - 5] == '#' && i / 5 > 0) ? move++ : move;
		}
	}
	if (move != 6 && move != 8)
		return (1);
	return (0);
}

int		validate_tet(char *buf, int bytes)
{
	int i;
	int blocks;

	i = -1;
	blocks = 0;
	while (++i < 20)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '#' && buf[i] != '.')
				return (1);
			if (buf[i] == '#' && ++blocks > 4)
				return (1);
		}
		else if (buf[i] != '\n')
			return (1);
	}
	if (bytes == 21 && buf[20] != '\n')
		return (1);
	if (valid_move(buf))
		return (1);
	return (0);
}

void	ft_putmap(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
	{
		ft_putstr(map->table[i]);
		write(1, "\n", 1);
	}
}

int		map_init(int tets)
{
	int size;

	size = 2;
	while (size * size < tets * 4)
		size++;
	return (size);
}

t_map	*create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	i = -1;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->table = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (++i < size)
	{
		j = -1;
		if (!(map->table[i] = ft_strnew(size + 1)))
			return (NULL);
		while (++j < size)
			map->table[i][j] = '.';
	}
	return (map);
}
