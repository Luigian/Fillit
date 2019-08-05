/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:22:33 by lusanche          #+#    #+#             */
/*   Updated: 2019/08/03 20:46:41 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map, t_tet *beg_5, int size_2)
{
	int		x;

	x = 0;
	while (map[x])
	{
		ft_putendl(map[x]);
		++x;
	}
	destroy_map(map, size_2);
	free(beg_5->figure[0]);
	free(beg_5->figure[1]);
	free(beg_5->figure[2]);
	free(beg_5->figure[3]);
	free(beg_5->figure);
	free(beg_5);
}

void	destroy_map(char **map, int size_1)
{
	int		x;

	x = size_1 + 1;
	while (x--)
	{
		free(map[size_1--]);
	}
	free(map);
}

int		solve_one_piece(char **map, t_tet *beg_2)
{
	int		*fig;

	if (!beg_2)
		return (1);
	fig = go_to_start_of_figure(beg_2);
	if (!(check_map(beg_2, map, fig)))
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
	t_tet		*beg_1;

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
			beg_1 = add_obj(beg_1, new);
		else
			beg_1 = new;
	}
	return (beg_1);
}
