/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:49:12 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/05 13:07:02 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct
{
		char	*name;
		char	*city;
		int		age;
}			player;

int		main(void)
{
	player.name = "Juan";
	player.city = "Mexico";
	player.age = 26;
	printf("[name] %s\n", player.name);
	printf("[city] %s\n", player.city);
	printf("[age] %d\n", player.age);
	return (0);
}
