/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_nested.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:49:12 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/05 13:05:59 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct ad
{
		int		number;
		char	*street;
		char	*city;
		char	*state;
		int		cp;
};

struct nm
{
		char	*first;
		char	*middle;
		char	*last;
};

struct
{
		struct	nm name;
		struct	ad adress;
		char	*nationality;
		int		age;
}				user;

int		main(void)
{
	user.name.first = "John";
	user.name.middle = "Robert"; 
	user.name.last = "Larson";
	user.adress.number = 6600;
	user.adress.street = "Dumbarton Cir";
	user.adress.city = "Fremont";
	user.adress.state = "CA";
	user.adress.cp = 94555;
	user.nationality = "Swedish";
	user.age = 25;
	printf("%s, ", user.name.last);
	printf("%s ", user.name.first);
	printf("%s\n", user.name.middle);
	printf("#%d ", user.adress.number);
	printf("%s, ", user.adress.street);
	printf("%s, ", user.adress.city);
	printf("%s, ", user.adress.state);
	printf("CP %d\n", user.adress.cp);
	printf("%s\n", user.nationality);
	printf("%d years old\n", user.age);
	return (0);
}
