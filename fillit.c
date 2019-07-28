/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:22:33 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/27 21:21:21 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		check_map(t_tet *beg, char **map, int *fig)
{
	int		x;
	int		y;
	int		*entry;

	x = 0;
	y = 0;
	while (map[x])
	{
		entry = select_entry_on_map(map, x, y);
		x = entry[0];
		y = entry[1];
		put_fig_on(beg->figure, map, fig, entry);
		if (count_assigns(map, beg->letter) == 4)
		{
			if (solve_one_piece(map, beg->next))
			{
				free(entry);
				return (1);
			}
		}
		restore_map_partial(map, beg->letter);
		++y;
	}
	free(entry);
	return (0);
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

int		main(int argc, char **argv)
{
	int			fd;
	t_tet		*beg;
	t_tet		*trav;
	char		**map;

	if (argc != 2)
	{
		write(1, "usage\n", 6);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY, 0);
	if (!(beg = read_validate_and_list(fd)))
		return (-1);
	trav = beg;
	while (1)
	{
		map = create_map(argc);
		if (solve_one_piece(map, trav))
			break ;
		else
			destroy_map(map, argc++);
	}
	free(beg);
	print_map(map);
	return (0);
}
