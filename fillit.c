/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:08:47 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/11 22:27:37 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int		invalid(char *s)
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
			++h;
		else if (s[i] == '\n')
		{
			++n;
			if (i != 4 && i != 9 && i != 14 && i != 19)
				return (1);
		}
		++i;
	}
	if (s[i] == '\0' && h == 4 && n == 4)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	
	if (argc != 2)
	{
		write(1, "usage\n", 6);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY, 0);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (invalid(buf) || ret != BUFF_SIZE)
	{
		write(1, "error\n", 6);
		return (-1);
	}
	ft_putstr(buf);
	return (0);
}
