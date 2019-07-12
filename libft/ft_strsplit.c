/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:04:28 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/26 22:50:09 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		cw;
	char	**array;
	int		wl;
	int		x;
	int		y;

	if (!s)
		return (NULL);
	cw = ft_count_words(s, c);
	if (!(array = ft_stranew(cw)))
		return (NULL);
	x = -1;
	while (cw--)
	{
		while (*s == c)
			++s;
		wl = ft_word_len(s, c);
		if (!(array[++x] = ft_strnew(wl)))
			return (NULL);
		y = 0;
		while (wl--)
			array[x][y++] = *s++;
	}
	return (array);
}
