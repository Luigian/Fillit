/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:26 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/26 20:53:40 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int len)
{
	char	**map;
	int		x;
	int		y;

	if (!(map = ft_stranew(len)))
		return (0);
	x = len;
	while (x--)
	{
		if (!(map[x] = ft_strnew(len)))
			return (0);
		y = len;
		while (y--)
			map[x][y] = '.';
		map[x][y + len] = '\0';
	}
	map[x + len] = NULL;
	return (map);
}

void	restore_map_partial(char **map, char c)
{
	int		x;
	int		y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == c)
				map[x][y] = '.';
			++y;
		}
		++x;
	}
}

void	destroy_map(char **map, int size)
{
	while (size--)
	{
		free(map[size]);
	}
	free(map);
}

void	print_map(char **map)
{
	int		x;

	x = 0;
	while (map[x])
	{
		ft_putendl(map[x]);
		++x;
	}
}
