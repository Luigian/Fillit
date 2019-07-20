/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:21:23 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/16 22:07:04 by lusanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# define BUFF_SIZE 21

typedef struct		s_tet
{
	char			**figure;
	char			letter;
	struct s_tet	*next;
}					t_tet;

#endif
