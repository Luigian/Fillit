/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:24:21 by lusanche          #+#    #+#             */
/*   Updated: 2019/05/23 21:21:57 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *temp2;

	temp = *alst;
	while (temp)
	{
		temp2 = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = temp2;
	}
	*alst = NULL;
}
