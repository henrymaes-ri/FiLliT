/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemaes-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:42:35 by hemaes-r          #+#    #+#             */
/*   Updated: 2018/05/21 15:42:37 by hemaes-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "fillit.h"

void	fillit_puterror(const char *prog)
{
	ft_putstr("usage: ");
	ft_putstr((char*)prog);
	ft_putstr(" [input_file]\n");
}

int		main(int argc, char **argv)
{
	char		buf[TET];
	t_tetlst	*list;
	t_map		*map;

	if (argc != 2)
	{
		fillit_puterror(argv[0]);
		return (1);
	}
	if (!(list = read_tet(open(argv[1], O_RDONLY), buf)))
	{
		ft_putstr("error\n");
		exit(0);
	}
	map = solve(list);
	ft_putmap(map);
	free_map(map);
	free_list(list);
	return (0);
}
