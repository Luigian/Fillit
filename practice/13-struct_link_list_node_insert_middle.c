/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_link_list_node_insert_middle.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 11:10:18 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/06 17:54:34 by lusanche         ###   ########.fr       */
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
type_list	*fill_list(type_list *head, int data);
type_list	*add_start_node(type_list *head);
type_list	*del_start_node(type_list *head);

type_list	*insert_after_node(type_list *head, int node)
{
	type_list	*trav;
	type_list	*new;

	trav = head;
	--node;
	while(node--)
		trav = trav->next;
	new = malloc(1);
	new->data = 50;
	new->next = trav->next;
	trav->next = new;	
	return (head);
}

int		main(void)
{
	type_list	*head;
	int			nodes;

	nodes = 10;	
	head = create_link_list(nodes);
	printf("Linked list creation\n");
	print_list(head);
	fill_list(head, 100);
	printf("Linked list filled\n");
	print_list(head);
	head = add_start_node(head);
	printf("Linked list start added\n");
	print_list(head);
	head = del_start_node(head);
	printf("Linked list start deleted\n");
	print_list(head);
	head = insert_after_node(head, 5);
	printf("Linked list node insertion \n");
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
	printf("-----------------------\n");
}

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

type_list	*add_start_node(type_list *head)
{
	type_list	*temp;

	temp = malloc(1);
	temp->data = 99;
	temp->next = head;
	head = temp;
	return (head);
}

type_list	*del_start_node(type_list *head)
{
	type_list	*temp;

	temp = head;
	head = head->next;
	free(temp);
	return (head);
}
