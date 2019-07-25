/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:45:05 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/25 16:50:50 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if (s[i] == '#' || s[i] == '\n')
		{
			s[i] == '#' ? ++h : ++n;
			if ((s[i] == '#' && ((h == 1 && s[i + 1] != '#' && s[i + 5] != '#')\
			|| (h == 2 && ((s[i + 1] != '#' && s[i + 5] != '#') && (s[i - 1] !=\
			'#' || s[i + 4] != '#'))) || (h == 4 && s[i - 1] != '#' && s[i - 5]\
			!= '#'))) || (s[i] == '\n' && (i != 4 && i != 9 && i != 14 && i !=\
			19 && i != 20)))
				return (1);
		}
		++i;
	}
	if (!s[i] && h == 4 && ((ret == (BUFF_SIZE - 2) && n == 3) ||\
		(ret == (BUFF_SIZE - 1) && n == 4) || (ret == BUFF_SIZE && n == 5)))
		return (0);
	return (1);
}

t_tet	*create_obj(char *buf, int pz)
{
	t_tet		*obj;
//	int			heigh;
//	int			wide;
	int			x;
	int			y;
	char		i;

	if (!(obj = (t_tet *)malloc(sizeof(t_tet) * 1)))
		return (NULL);
	obj->letter = pz + 64;
	x = 4;
	if (!(obj->figure = (char **)malloc(sizeof(char *) * x + 1)))
		return (NULL);
	i = 18;
	while (x--)
	{
		y = 4;
		if (!(obj->figure[x] = (char *)malloc(sizeof(char) * y + 1)))
			return (NULL);
		while (y--)
		{
			if (buf[i] == '#')
				obj->figure[x][y] = obj->letter;
			else if (buf[i] == '.')
				obj->figure[x][y] = '.';
			--i;
		}
		obj->figure[x][4] = '\0';
		--i;
	}
	obj->figure[4] = NULL;
	obj->next = NULL;
	return (obj);
}
/*
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
*/
t_tet	*add_obj(t_tet *beg, t_tet *new)
{
	t_tet	*trav;

	trav = beg;
	while (trav->next)
		trav = trav->next;
	trav->next = new;
	return (beg);
}
