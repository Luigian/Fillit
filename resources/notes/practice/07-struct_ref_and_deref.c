
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ref_and_deref.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:08:10 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/06 09:14:53 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// REFERENCE

struct 
{
	char	*name;
	char	*area;
	int		stars;
}			hotel;

int		main(void)
{
	hotel.name = "Corona",
	printf("[By reference]: %s\n", hotel.name);
	return (0);
}

// DE-REFERENCE 

struct hotel 
{
	char	*name;
	char	*area;
	int		stars;
};

int		main(void)
{
	struct hotel	*p;
	p->name = "Rey Sol";	
	printf("[By dereference]: %s\n", p->name);
	return (0);
}

// DE-REFERENCE TYPEDEF

typedef struct 
{
	char	*name;
	char	*area;
	int		stars;
}			hotel;

int		main(void)
{
	hotel	*p;
	p->name = "Santa Isabel";	
	printf("[By dereference typedef]: %s\n", p->name);
	return (0);
}
