/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:08:47 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/24 20:21:39 by lusanche         ###   ########.fr       */
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
		if (trav->next != NULL)
		printf("\n");
		trav = trav->next;
	}
}

void	print_list_line(t_tet *beg)
{
	t_tet	*trav;
	trav = beg;
	while (trav)
	{
		printf("%c\t", trav->letter);
		trav = trav->next;
	}
	printf("\n");
}

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
			map[x][y] = '-';
			++y;
		}
		map[x][y] = '\0';
		++x;
	}
	map[x] = NULL;
	return (map);
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



void	print_map(char **map)	
{
	int		x;

	x = 0;
	while (map[x])
	{
		ft_putendl(map[x]);
		++x;
	}
	printf("%s\n", map[x]);
}

////////////////////////////////////////////////////////////////////////
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

int		*select_entry_on_map(char **map, int x, int y)
{
	int		found;
	int		*entry;
	
	found = 0;
	while (map[x] && !found)
	{
		while (map[x][y] && !found)
		{
			if (map[x][y] == '-')
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
////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////

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

int		put_figure_on_map(char **figure, char **map, int i, int j, int x, int y)
{
	if (map[x] && map[x][y] == '-')
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

//////////////////////////////////////////////////////////////////////////////	

int		solve_one_piece(char **map, t_tet *beg)
{
	int		i;
	int		j;
	int		*fig;
	int		x;
	int		y;
	int		*entry;

	if (!beg)
		return(1);
	print_list_line(beg);
	fig = go_to_start_of_figure(beg);
	i = fig[0];
	j = fig[1];
	x = 0;
	y = 0;
	free(fig);
	while (map[x])
	{
		entry = select_entry_on_map(map, x, y);
		x = entry[0];
		y = entry[1];
		free(entry);
		printf("i: %d\tj: %d\t|    x: %d\ty: %d\n", i, j, x, y);////////print
		put_figure_on_map(beg->figure, map, i, j, x, y);
		if (count_assigns(map, beg->letter) == 4)			 
		{
			if (solve_one_piece(map, beg->next))
				return (1);
		}
		restore_map_partial(map, beg->letter);
		++y;
	}
	return (0);
}

//////////////////////////////////////////////////////////////////////////////

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
	int			perm;

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
	//////////////////////////////////////////////////////////////
	size = 2;
	trav = beg;
	while(1)//
	{//
		map = create_map(size);
		print_map(map);////////////print map				
		if (solve_one_piece(map, trav))
			break ;
		else
			++size;
	}
	print_map(map);						////////////////////print map
		
		

	
	
	
	
	
	
/*	find = 0;					//	<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	size = 5;
	while (!find)
	{
//		perm = factorial(pz);				
		map = create_map(size);
		print_map(map);						////////////////////				
		while (find == 0)			
		{
//			beg = sorting_list(beg, perm, pz);
			trav = beg;
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
			--perm;
		}			
		if (find == 0)
		{
			free(map);
			++size;
		}
	}
	print_map(map);					/////////////////////
*/	return (0);
}
