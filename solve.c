/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:34:27 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/25 14:41:24 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		while(map[x][y])
		{
			if (map[x][y] == c)
				++count;
			++y;
		}
		++x;
	}
	return (count);
}

int		put_figure_on_map(char **figure, char **map, int i, int j, int x, int y)
{
	if (map[x] && map[x][y] == '.')
	{
		map[x][y] = figure[i][j];
		if (j < 3 && figure[i][j + 1] != '.')
		{
			put_figure_on_map(figure, map, i, ++j, x, ++y);
			--j;
			--y;
		}
		if (i < 3 && figure[i + 1][j] != '.')
		{
			put_figure_on_map(figure, map, ++i, j, ++x, y);
			--i;
			--x;
		}
		if (j > 0 && figure[i][j - 1] != '.')
		{
			put_figure_on_map(figure, map, i, --j, x, --y);
		}
		return (1);
	}
	else
		return (0);
}

int		*select_entry_on_map(char **map, int x, int y)
{
	int		found;
	int		*entry;

	found = 0;
	while (map[x] && !found)
	{
		while (map[x][y] && !found)
		{
			if (map[x][y] == '.')
				found = 1;
			else
				++y;
		}
		if (!found)
		{
			++x;
			y = 0;
		}
	}
	if(!(entry = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	entry[0] = x;
	entry[1] = y;
	return (entry);
}

int		*go_to_start_of_figure(t_tet *beg)
{
	t_tet	*trav;
	int		i;
	int		j;
	int		first;
	int		*fig;

	trav = beg;
	i = 0;
	first = 0;
	while (trav->figure[i] && !first)
	{
		j = 0;
		while (trav->figure[i][j] && !first)
		{
			if (trav->figure[i][j] != '.')
				first = 1;
			else
				++j;
		}
		if (!first)
			++i;
	}
	if(!(fig = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	fig[0] = i;
	fig[1] = j;
	return (fig);
}
