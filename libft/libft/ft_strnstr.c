/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:25:10 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/26 18:09:17 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		h;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	j = 0;
	h = 0;
	while (haystack[i] && len > i)
	{
		while (haystack[i] && haystack[i] != needle[j] && len > i)
			++i;
		while (needle[j] && (haystack[i] == needle[j] && len > i))
		{
			++i;
			++j;
		}
		if (!needle[j])
			return ((char *)&haystack[i - j]);
		j = 0;
		++h;
		i = h;
	}
	return (NULL);
}
