/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_link_list_double.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:59:44 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/06 19:45:07 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct			s_list
{
	int					data;
	struct s_list		*prev;
	struct s_list		*next;
}						t_list;

void	print_list(t_list *head);
void	rev_print_list(t_list *head);

t_list	*created_link_list_double(int nodes)
{
	t_list	*beg;
	t_list	*trav;
	t_list	*asst;
	int		info;

	beg = malloc(sizeof(t_list) * 1);
	beg->prev = NULL;
	trav = beg;
	asst = beg;
	--nodes;
	info = 1000;
	while (nodes--)
	{
		trav->data = info;
		trav->next = malloc(sizeof(t_list) * 1);
		trav = trav->next;
		trav->prev = asst;
		asst = asst->next;
		info += 500;
	}
	trav->data = info;
	trav->next = NULL;
	return (beg);
}

int		main(void)
{
	t_list	*head;
	int		nodes;

	nodes = 5;
	head = created_link_list_double(nodes);
	printf("Double linked list created and filled\n");
	print_list(head);
	printf("Double linked list reverse print\n");
	rev_print_list(head);
	return (0);
}

////////////////////////////////////////////////////////////////////////////////////

void	print_list(t_list *head)
{
	t_list		*trav;
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

void	rev_print_list(t_list *head)
{
	t_list		*trav;
	int			node;
	
	trav = head;
	node = 0;
	while (trav->next)
	{
		trav = trav->next;
		++node;	
	}
	while (trav)
	{
		printf("[obj %d data]: %d\n", node, trav->data);
		trav = trav->prev;
		--node;
	}
	printf("-----------------------\n");
}
