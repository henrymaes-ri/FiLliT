/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaes-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 20:55:08 by hemaes-r          #+#    #+#             */
/*   Updated: 2018/05/23 20:55:10 by hemaes-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define TAB tet->table[i]
#define NEXT tet->next

void		add_width_height(t_tetlst *list, t_tetlst *tet)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (TAB.x + 1 > tet->width)
			tet->width = TAB.x + 1;
		if (TAB.y + 1 > tet->height)
			tet->height = TAB.y + 1;
	}
	if (NEXT)
		add_width_height(list, NEXT);
}

void		trim_to_shape(t_tetlst *list, t_tetlst *tet)
{
	int i;
	int min_x;
	int min_y;

	i = -1;
	min_y = 3;
	min_x = 3;
	while (++i < 4)
	{
		TAB.x < min_x ? min_x = TAB.x : min_x;
		TAB.y < min_y ? min_y = TAB.y : min_y;
	}
	if (min_x < 3 || min_y < 3)
	{
		i = -1;
		while (++i < 4)
		{
			TAB.x -= min_x;
			TAB.y -= min_y;
		}
	}
	if (NEXT)
		trim_to_shape(list, NEXT);
}

t_tetlst	*store_data(t_tetlst *tet, char *buf, char order)
{
	int c;
	int i;

	i = 0;
	c = -1;
	if (order != 'A')
	{
		if (!(NEXT = create_tet()))
			return (NULL);
		tet = NEXT;
	}
	tet->order = order;
	tet->width = 0;
	tet->height = 0;
	while (++c < 20)
	{
		if (buf[c] == '#')
		{
			TAB = *(t_point*)malloc(sizeof(t_point));
			TAB.x = c % 5;
			tet->table[i++].y = c / 5;
		}
	}
	return (tet);
}

t_tetlst	*read_tet(int fd, char *buf)
{
	int			bytes;
	int			t_bytes;
	t_tetlst	*list;
	t_tetlst	*curr;
	char		order;

	if (!(list = create_tet()))
		return (NULL);
	order = 'A';
	curr = list;
	t_bytes = 0;
	while ((bytes = read(fd, buf, TET)) >= 20)
	{
		if (validate_tet(buf, bytes) && order <= 'Z')
			return (NULL);
		if (!(curr = store_data(curr, buf, order++)))
			return (NULL);
		t_bytes += bytes;
	}
	if (!t_bytes || t_bytes != (order - 'A') * 21 - 1)
		return (NULL);
	trim_to_shape(list, list);
	add_width_height(list, list);
	close(fd);
	return (list);
}

t_tetlst	*create_tet(void)
{
	t_tetlst	*tet;

	if (!(tet = (t_tetlst*)malloc(sizeof(t_tetlst))))
		return (NULL);
	tet->next = NULL;
	return (tet);
}
