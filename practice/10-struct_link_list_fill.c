/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_link_list_fill.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:10:18 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/06 16:19:54 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct			struct_list
{
	int					data;
	struct struct_list 	*next;
}						type_list;

type_list	*create_link_list(int nodes);
void	print_list(type_list *head);

type_list	*fill_list(type_list *head, int data)
{
	type_list	*trav;

	trav = head;
	while (trav)
	{
		trav->data = data;
		trav = trav->next;
		++data;
	}
	return (head);
}

int		main(void)
{
	type_list	*head;
	int			nodes;

	nodes = 10;	
	head = create_link_list(nodes);
	print_list(head);
	fill_list(head, 100);
	print_list(head);
	return (0);
}

/////////////////////////////////////////////////////////////////////////////////

type_list	*create_link_list(int nodes)
{
	type_list	*beg;
	type_list	*trav;

	beg = malloc(1);
	trav = beg;
	--nodes;
	while (nodes--)
	{
		trav->data = 0;
		trav->next = malloc(1);
		trav = trav->next;
	}
	trav->data = 0;
	trav->next = NULL;
	return (beg);
}

void	print_list(type_list *head)
{
	type_list	*trav;
	int			node;
	
	trav = head;
	node = 0;
	while (trav)
	{
		printf("[obj %d data]: %d\n", node, trav->data);
		trav = trav->next;
		++node;
	}
}
