/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:50:26 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/28 21:55:45 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		count_assigns(char **map, char c)
{
	int		count;
	int		x;
	int		y;

	x = 0;
	count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == c)
				++count;
			++y;
		}
		++x;
	}
	return (count);
}

void	add_sub_int_array(int *fig, int *entry, int ind, char sign)
{
	if (sign == '+')
	{
		++fig[ind];
		++entry[ind];
	}
	else if (sign == '-')
	{
		--fig[ind];
		--entry[ind];
	}
}
