/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers_arithmetic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:47:29 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/05 13:09:36 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	int		x;
	int		y;
	int		z[] = {3, 6, 9, 12, 15, 18, 21, 24, 27, 30};
	int		*p;

	x = 10;
	printf("[x]%d\n", x);
	y = 2;
	printf("[y]%d\n", y);
	p = &x;			// p apunta ahora a la variable x
	printf("[*p]%d\n", *p);
	y = *p;			// y contiene ahora el valor de 10
	printf("[y]%d\n", y);
	*p = 0;			// x es asignada con un valor de cero a través del apuntador p.
	printf("[x]%d\n", x);
	p = &z[2];		// p apunta ahora a z[2]
	printf("[*p]%d\n", *p);
	*p = *p + 2;	// incrementa en dos lo apuntado por p.
	printf("[*p]%d\n", *p);
	++*p;			// incrementa en uno lo apuntado por p.
	printf("[*p]%d\n", *p);
	(*p)++;			// incrementa en uno lo apuntado por p. \
					los paréntesis son necesarios para que no incremente a p.
	printf("[*p]%d\n", *p);
	return (0);
}
