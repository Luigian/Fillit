/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:36:20 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/29 17:30:02 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	if (len == 0 || dst == src)
		return (dst);
	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (p_src < p_dst)
		while (len--)
		{
			*(p_dst + len) = *(p_src + len);
		}
	else
		while (len--)
		{
			*p_dst = *p_src;
			++p_dst;
			++p_src;
		}
	return (dst);
}
