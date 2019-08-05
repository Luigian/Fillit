/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:04:24 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/23 22:46:55 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *str, char d)
{
	int		t;
	int		words;

	words = 0;
	while (*str == d)
		++str;
	while (*str)
	{
		t = 1;
		while (*str && *str != d)
		{
			(t) ? ++words : 0;
			t = 0;
			++str;
		}
		while (*str == d)
			++str;
	}
	return (words);
}
