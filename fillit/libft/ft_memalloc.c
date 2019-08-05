/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:33:06 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/26 22:25:02 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*fresh;

	fresh = NULL;
	if (!size)
		;
	else
	{
		if (!(fresh = (char *)malloc(sizeof(char) * size)))
			return (NULL);
		while (size)
			fresh[--size] = 0;
	}
	return ((void *)fresh);
}
