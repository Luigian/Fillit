/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 11:29:33 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/25 22:08:38 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	while (n--)
	{
		*p_dst = *p_src;
		if (*p_src == (unsigned char)c)
			return (++p_dst);
		++p_dst;
		++p_src;
	}
	return (NULL);
}
