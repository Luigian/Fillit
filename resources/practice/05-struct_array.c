/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:08:10 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/05 18:48:20 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct book
{
	char	*title;
	char	*author;
	int		price;
};

int		main(void)
{
	char			*alphabet;
	struct book		catalogue[3];
	char			*t[3];
   	char			*a[3];
	int				p[3];
	int				i;

	alphabet = "abcdefghijklmnopqrstuvwxyz";
	t[0] = "Quixote";
	t[1] = "Iliada";
	t[2] = "Hamlet";
	a[0] = "Cervantes";
	a[1] = "Homero";
	a[2] = "Shakespeare";
	p[0] = 30;
	p[1] = 25;
	p[2] = 50;
	i = 0;
	while (i < 3)
	{
		catalogue[i].title = t[i];
		catalogue[i].author = a[i];
		catalogue[i].price = p[i];
		++i;
	}
	printf("%s\n", alphabet);
	i = 0;
	while (i < 3)
	{
		printf("catalogue[%d]: Title: %s / ", i, catalogue[i].title);
		printf("Author: %s / ", catalogue[i].author);
		printf("Price: $%d\n", catalogue[i].price);
		++i;
	}
	return (0);
}
