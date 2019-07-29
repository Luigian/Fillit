/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 21:47:11 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/28 22:00:47 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int			fd;
	t_tet		*beg;
	t_tet		*trav;
	char		**map;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY, 0);
	if (!(beg = read_validate_and_list(fd)))
		exit(0);
	close(fd);
	trav = beg;
	while (1)
	{
		map = create_map(argc);
		if (solve_one_piece(map, trav))
			break ;
		destroy_map(map, argc++);
	}
	free(beg);
	print_map(map);
	return (0);
}
