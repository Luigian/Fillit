/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:41:21 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/26 16:39:31 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*needle_first_element;
	char	*haystack_first_element;

	if (!*needle)
		return ((char *)haystack);
	needle_first_element = (char *)needle;
	haystack_first_element = (char *)haystack;
	i = 0;
	while (*haystack)
	{
		while (*haystack && *haystack != *needle)
			++haystack;
		while (*haystack && *needle && (*haystack == *needle))
		{
			++haystack;
			++needle;
		}
		if (!*needle)
			return ((char *)haystack - ft_strlen(needle_first_element));
		++i;
		needle = needle_first_element;
		haystack = haystack_first_element + i;
	}
	return (NULL);
}
