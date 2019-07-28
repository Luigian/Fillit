/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 21:24:09 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/23 21:34:36 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *ptr;

	ptr = (char *)b;
	while (len--)
	{
		*ptr = (unsigned char)c;
		++ptr;
	}
	return (b);
}
