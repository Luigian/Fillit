/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:45:05 by lusanche          #+#    #+#             */
/*   Updated: 2019/08/03 20:48:52 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*add_obj(t_tet *beg_1, t_tet *new)
{
	t_tet	*trav;

	trav = beg_1;
	while (trav->next)
		trav = trav->next;
	trav->next = new;
	return (beg_1);
}

int		create_figure(t_tet *obj, char *buf)
{
	int		x;
	int		y;
	int		i;

	x = 4;
	if (!(obj->figure = (char **)malloc(sizeof(char *) * x + 1)))
		return (0);
	i = 18;
	while (x--)
	{
		y = 4;
		if (!(obj->figure[x] = (char *)malloc(sizeof(char) * y + 1)))
			return (0);
		while (y--)
		{
			if (buf[i] == '#' || buf[i] == '.')
				obj->figure[x][y] = (buf[i] == '#' ? obj->letter : '.');
			--i;
		}
		obj->figure[x][4] = '\0';
		--i;
	}
	obj->figure[4] = NULL;
	return (1);
}

t_tet	*create_obj(char *buf, int pz)
{
	t_tet	*obj;

	if (!(obj = (t_tet *)malloc(sizeof(t_tet) * 1)))
		return (NULL);
	obj->letter = pz + 64;
	if (!(create_figure(obj, buf)))
		return (NULL);
	obj->next = NULL;
	return (obj);
}

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
