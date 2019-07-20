/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:08:47 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/19 20:55:14 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		invalid(char *s, int ret)
{	
	int		i;
	int		h;
	int		n;

	i = 0;
	h = 0;
	n = 0;
	while (s[i] && (s[i] == '.' || s[i] == '#' || s[i] == '\n'))
	{
		if (s[i] == '#')
		{
			++h;
			if (h == 1 && s[i + 1] != '#' && s[i + 5] != '#')
				return (1);
			if (h == 2 && ((s[i + 1] != '#' && s[i + 5] != '#') &&\
						(s[i - 1] != '#' || s[i + 4] != '#')))
				return (1);
			
			if (h == 4 && s[i - 1] != '#' && s[i - 5] != '#')
				return (1);
		}	
		else if (s[i] == '\n')
		{
			++n;
			if (i != 4 && i != 9 && i != 14 && i != 19 && i != 20)
				return (1);
		}
		++i;
	}
	if (s[i] == '\0' && h == 4 && ((ret == (BUFF_SIZE - 2) && n == 3) ||\
				(ret == (BUFF_SIZE - 1) && n == 4) || (ret == BUFF_SIZE && n == 5)))
		return (0);
	return (1);
}

t_tet	*create_obj(char *buf, int pz)
{
	t_tet		*obj;
	int			heigh;
	int			wide;
	int			x;
	int			y;
	char		i;
	
	if (!(obj = (t_tet *)malloc(sizeof(t_tet) * 1)))
			return (NULL);
	obj->letter = pz + 64;
	heigh = 4;
	if (!(obj->figure = (char **)malloc(sizeof(char *) * heigh + 1)))
		return (NULL);
	x = 0;
	i = 0;
	while (heigh--)
	{	
		wide = 4;
		if (!(obj->figure[x] = (char *)malloc(sizeof(char) * wide + 1)))
			return (NULL);
		y = 0;
		while (wide--)
		{
			if (buf[i] == '#')
				obj->figure[x][y] = obj->letter;
			else if (buf[i] == '.')
				obj->figure[x][y] = '.';
			++y;
			++i;
		}
		obj->figure[x][y] = '\0';
		++i;
		++x;
	}
	obj->figure[x] = NULL;
	obj->next = NULL;
	return (obj);
}

t_tet	*add_obj(t_tet *beg, t_tet *new)
{
	t_tet	*trav;

	trav = beg;
	while (trav->next)
		trav = trav->next;
	trav->next = new;
	return (beg);
}

void	print_list(t_tet *beg)
{
	t_tet	*trav;
	int		i;

	trav = beg;
	while (trav)
	{
		i = 0;
		while (trav->figure[i])
		{
			printf("%s\n", trav->figure[i]);
			++i;
		}
		printf("\n");
		trav = trav->next;
	}
}

char	**create_map(int len)
{
	char 	**map;
	int		x, y = 0;	
	int		heigh, wide;

	heigh = len;
	if (!(map = ft_stranew(heigh/* + 1*/)))
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
			map[x][y] = '-';
			++y;
		}
		map[x][y] = '\0';
		++x;
	}
/*	wide = len;
	if (!(map[x] = ft_strnew(wide)))
		return (0);
	y = 0;
	while (wide--)
	{
		map[x][y] = '\0';
		++y;
	}
	map[x][y] = '\0';
	++x;*/
	map[x] = NULL;
	return (map);
}

int		fillity(char **map, char **figure, int x, int y, int i, int j)
{
	if (map[x] && map[x][y] == '-')
	{
		map[x][y] = figure[i][j];
		if (j < 3 && figure[i][j + 1] != '.')
		{
			fillity(map, figure, x, ++y, i, ++j);
			--y;
			--j;
		}
		if (i < 3 && figure[i + 1][j] != '.')
		{
			fillity(map, figure, ++x, y, ++i, j);
			--x;
			--i;	
		}
		if (j > 0 && figure[i][j - 1] != '.')
		{
			fillity(map, figure, x, --y, i, --j);
		}	
		return (1);
	}
//	else if (map[x][y] == '2')
		
	else 
		return (0);
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
				map[x][y] = '-';
			++y;
		}
		++x;
	}
}

void	restore_map_total(char **map)
{
	int		x;
	int		y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while(map[x][y])
		{
			map[x][y] = '-';
			++y;
		}
		++x;
	}
}

int		explore_map(t_tet *beg, int i, int j, char **map)
{
	int		x, y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			fillity(map, beg->figure, x, y, i, j);
			if (count_assigns(map, beg->letter) == 4)			 
				return (1);
			restore_map_partial(map, beg->letter);
			++y;
		}
		++x;
	}
	return (0);
}

//UNIFY MERGE AND EXPLORE

int		find_hash(t_tet *beg, char **map)
{
	t_tet	*trav;
	int		i;
	int		j;

	trav = beg;
	i = 0;
	j = 0;
	while (trav->figure[i])
	{
		j = 0;
		while (trav->figure[i][j])
		{
			if (trav->figure[i][j] != '.') ////////
			{
				if (explore_map(trav, i, j, map))
					return (1);
				else
					return (0);
			}
			++j;
		}
		++i;
	}
	return (0);	
}

/*
int		max_wide(char **map)	
{
	int		wide;
	int		x;
	int		y;

	wide = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '-')
			{
				if (y > wide)
					wide = y;
				break ;
			}
			++y;
		}
		++x;

	}
	return (wide);
}*/
/*		
int		max_heigh(char **map)	
{
	int		heigh;
	int		x;
	int		y;

	heigh = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != '-')
			{
				if (x > heigh)
					heigh = x;
				break ;
			}
			++y;
		}
		++x;
	}
	return (++heigh);
}*/
/*
t_tet	*twist_lasts(t_tet *beg)
{
	t_tet	*trav;
	t_tet	*prev;

	trav = beg;
	prev = beg->next;
	while (trav->next)
		trav = trav->next;
	beg->next = trav;
	trav->next = prev;
	prev->next = NULL;
	return (beg);
}
*/

void	print_map(char **map)	
{
	int		x;

	x = 0;
	while (map[x])
	{
//		printf("%s\n", map[x]);
		ft_putendl(map[x]);
		++x;
	}
	printf("%s\n", map[x]);
}

t_tet	*sorting_list(t_tet *beg/*, int fac*/)
{
	t_tet	*trav;
	t_tet	*prev;
	t_tet	*aprev;
	int		len;
	int		ite;

	trav = beg;
	while (trav->next)
		trav = trav->next;
	len = trav->letter - 64;
	ite = len;
	if (len > 2)
	{
		aprev = beg;
		while (ite - 3)
		{
			aprev = aprev->next;
			--ite;
		}
		prev = aprev->next;
		aprev->next = trav;
		trav->next = prev;
		prev->next = NULL;
	}		
	return (beg);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			pz;
	t_tet		*new;
	t_tet		*beg;
	t_tet		*trav;
	char		**map;
	int			size;
	int			find;
//	int			fac;

	if (argc != 2)
	{
		write(1, "usage\n", 6);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY, 0);
	ret = BUFF_SIZE;
	pz = 0;
	while (ret == BUFF_SIZE)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if (ret < (BUFF_SIZE - 2) || invalid(buf, ret) || ++pz > 26)
		{
			write(1, "error\n", 6);
			return (-1);
		}	
		new = create_obj(buf, pz);
		if (new->letter != 'A')
			beg = add_obj(beg, new);
		else
			beg = new;
	}
	print_list(beg);
	find = 0;
	size = 4;
//	fac = 1;
	while (!find)
	{
		map = create_map(size);
		while (/*sort_options &&*/ find == 0)
		{
			trav = sorting_list(beg/*, fac++*/);
			while (trav)
			{
				if (!(find_hash(trav, map)))
				{
					find = 0;
					break ;
				}
				else
					find = 1;
				trav = trav->next;
			}
			if (find == 0)
				restore_map_total(map);
		}
		if (find == 0)
		{
			free(map);
			++size;
		}
	}
/*	find = 0;	BACKUP START
	size = 2;
	while (!find)
	{
		map = create_map(size);*/
//		while (sort_options && find == 0)
//		{
//			trav = sorting_list(beg);*/
/*			trav = beg;
			while (trav)
			{
				if (!(find_hash(trav, map)))
				{
					find = 0;
					break ;
				}
				else
					find = 1;
				trav = trav->next;
			}*/
//			if (find == 0)
//				restore_map_total;
//		}
/*		if (find == 0)
		{
			free(map);
			++size;
		}
	}		BACK UP END*/
	print_map(map);
	return (0);
}
