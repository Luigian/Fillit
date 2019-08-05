/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:45:16 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/26 20:20:01 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strcon;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	if (!(strcon = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (s1[i])
	{
		strcon[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		strcon[i] = s2[j];
		++i;
		++j;
	}
	return (strcon);
}
