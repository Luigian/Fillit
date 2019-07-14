/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:08:47 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/13 22:25:36 by lusanche         ###   ########.fr       */
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
			if (h < 1 && s[i + 1] != '#' && s[i + 5] != '#')
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

int		fig_heigh(char *buf)
{
	int		i;
	int		nl;
	int		res;

	i = 0;
	nl = 1;
	res = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			nl = 1;
		else if (buf[i] == '#')
			if (nl)
			{
				++res;
				nl = 0;
			}
		++i;
	}
	return (res);
}

int		fig_wide(char *i)
{
	int		j;

	j = 0;
//	if (*i == '\n')
//		++i;
//	while (!j)
//	{
		while (*i != '\n')
		{
			if (*i == '#')
				++j;
		 	++i;
		}
//		++i;
//	}
	return (j);
}

t_tet	*create_obj(char *buf)
{
	t_tet		*obj;
	int			heigh;
	int			wide;
	int			x;
	int			y;
	char		*i;
	
	if (!(obj = (t_tet *)malloc(sizeof(t_tet) * 1)))
			return (NULL);
	heigh = fig_heigh(buf);
	if (!(obj->figure = (char **)malloc(sizeof(char *) * heigh + 1)))
		return (NULL);
	x = 0;
	i = buf;
	while (heigh--)
	{	
		wide = 0;
		while (!wide)
		{
			wide = fig_wide(i);
			i += 5;
		}
		if (!(obj->figure[x] = (char *)malloc(sizeof(char) * wide + 1)))
			return (NULL);
		y = 0;
		while (wide--)
		{
			obj->figure[x][y] = '#';
			++y;
		}
		obj->figure[x][y] = '\0';
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

int		main(int argc, char **argv)
{
	int			fd;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			pz;
	t_tet		*new;
	t_tet		*beg;

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
		new = create_obj(buf);
		if (new->letter != 'A')
			beg = add_obj(beg, new);
		else
			beg = new;
		ft_putendl(beg->figure[0]);
		ft_putendl(beg->figure[1]);
		ft_putendl(beg->figure[2]);
		printf("%s\n", new->figure[3]);
	}
	return (0);
}
