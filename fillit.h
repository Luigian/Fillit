/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:21:23 by lusanche          #+#    #+#             */
/*   Updated: 2019/07/25 15:06:43 by lusanche         ###   ########.fr       */
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

t_tet	*read_validate_and_list(int fd);
int		invalid(char *s, int ret);
void	print_map(char **map);
void	destroy_map(char **map, int size);
int		solve_one_piece(char **map, t_tet *beg);
void	restore_map_partial(char **map, char c);
int		count_assigns(char **map, char c);
int		put_figure_on_map(char **figure, char **map, int i, int j, int x, int y);
int		*select_entry_on_map(char **map, int x, int y);
int		*go_to_start_of_figure(t_tet *beg);
char	**create_map(int len);
t_tet	*add_obj(t_tet *beg, t_tet *new);
t_tet	*create_obj(char *buf, int pz);

#endif
