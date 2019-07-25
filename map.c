/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:26 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/25 13:31:37 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int len)
{
	char 	**map;
	int		x, y = 0;
	int		heigh, wide;

	heigh = len;
	if (!(map = ft_stranew(heigh)))
		return (0);
	x = 0;
	while (heigh--)
	{
		wide = len;
		if (!(map[x] = ft_strnew(wide)))
			return (0);
		y = 0;
		while (wide--)
		{
			map[x][y] = '.';
			++y;
		}
		map[x][y] = '\0';
		++x;
	}
	map[x] = NULL;
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
		while(map[x][y])
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
