/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:34:27 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/27 21:43:32 by lusanche         ###   ########.fr       */
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

int		put_fig_on(char **figure, char **map, int *fig, int *entry)
{
	if (map[entry[0]] && map[entry[0]][entry[1]] == '.')
	{
		map[entry[0]][entry[1]] = figure[fig[0]][fig[1]];
		if (fig[1] < 3 && figure[fig[0]][fig[1] + 1] != '.')
		{
			add_sub_int_array(fig, entry, 1, '+');
			put_fig_on(figure, map, fig, entry);
			add_sub_int_array(fig, entry, 1, '-');
		}
		if (fig[0] < 3 && figure[fig[0] + 1][fig[1]] != '.')
		{
			add_sub_int_array(fig, entry, 0, '+');
			put_fig_on(figure, map, fig, entry);
			add_sub_int_array(fig, entry, 0, '-');
		}
		if (fig[1] > 0 && figure[fig[0]][fig[1] - 1] != '.')
		{
			add_sub_int_array(fig, entry, 1, '-');
			put_fig_on(figure, map, fig, entry);
			add_sub_int_array(fig, entry, 1, '+');
		}
		return (1);
	}
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
	if (!(entry = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	entry[0] = x;
	entry[1] = y;
	return (entry);
}

int		*go_to_start_of_figure(t_tet *beg)
{
	int		i;
	int		j;
	int		first;
	int		*fig;

	i = 0;
	first = 0;
	while (beg->figure[i] && !first)
	{
		j = 0;
		while (beg->figure[i][j] && !first)
		{
			if (beg->figure[i][j] != '.')
				first = 1;
			else
				++j;
		}
		if (!first)
			++i;
	}
	if (!(fig = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	fig[0] = i;
	fig[1] = j;
	return (fig);
}
