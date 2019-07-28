/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_link_list_basic.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:10:18 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/06 16:22:40 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct			struct_list
{
	int					data;
	struct struct_list 	*next;
}						type_list;

int		main(void)
{
	type_list	*head;
	type_list	*trav;

//	head = malloc(1);
	head->data = 10;
	head->next = NULL;
	trav = head->next;
	trav = malloc(1);
	trav->data = 5;
	trav->next = NULL;
	printf("[head]: %d\n", head->data);
	printf("[trav]: %d\n", trav->data);
	return (0);
}
