/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaes-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 16:00:44 by hemaes-r          #+#    #+#             */
/*   Updated: 2018/05/25 16:00:45 by hemaes-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

void		ft_putstr_fd(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

size_t		ft_lstsize(t_tetlst *beginlist)
{
	size_t		i;
	t_tetlst	*size;

	i = 0;
	size = beginlist;
	while (size)
	{
		size = size->next;
		i++;
	}
	return (i);
}

void		ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void		free_map(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
		ft_memdel((void**)&(map->table[i]));
	ft_memdel((void**)(map->table));
	ft_memdel((void**)&map);
}

t_tetlst	*free_list(t_tetlst *list)
{
	t_tetlst *tet;

	while (list)
	{
		tet = list->next;
		ft_memdel((void**)&list);
		list = tet;
	}
	return (NULL);
}
