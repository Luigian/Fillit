/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:22:33 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/28 22:00:35 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	destroy_map(char **map, int size)
{
	while (size--)
	{
		free(map[size]);
	}
	free(map);
}

int		solve_one_piece(char **map, t_tet *beg)
{
	int		i;
	int		j;
	int		*fig;

	if (!beg)
		return (1);
	fig = go_to_start_of_figure(beg);
	if (!(check_map(beg, map, fig)))
	{
		free(fig);
		return (0);
	}
	free(fig);
	return (1);
}

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

t_tet	*read_validate_and_list(int fd)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			pz;
	t_tet		*new;
	t_tet		*beg;

	ret = BUFF_SIZE;
	pz = 0;
	while (ret == BUFF_SIZE)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (ret < (BUFF_SIZE - 2) || invalid(buf, ret) || ++pz > 26)
		{
			write(1, "error\n", 6);
			return (NULL);
		}
		if (!(new = create_obj(buf, pz)))
			return (NULL);
		if (new->letter != 'A')
			beg = add_obj(beg, new);
		else
			beg = new;
	}
	return (beg);
}
