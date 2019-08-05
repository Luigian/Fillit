/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusanche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:21:23 by lusanche          #+#    #+#             */
/*   Updated: 2019/08/03 20:31:46 by lusanche         ###   ########.fr       */
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

t_tet				*read_validate_and_list(int fd);
int					invalid(char *s, int ret);
t_tet				*create_obj(char *buf, int pz);
int					create_figure(t_tet *obj, char *buf);
t_tet				*add_obj(t_tet *beg_1, t_tet *new);
char				**create_map(int len);
int					solve_one_piece(char **map, t_tet *beg_2);
int					*go_to_start_of_figure(t_tet *beg_3);
int					check_map(t_tet *beg_4, char **map, int *fig);
int					*select_entry_on_map(char **map, int x, int y);
int					put_fig_on(char **figure, char **map, int *fig, int *entry);
void				add_sub_int_array(int *fig, int *entry, int ind, char sign);
int					count_assigns(char **map, char c);
void				restore_map_partial(char **map, char c);
void				destroy_map(char **map, int size_1);
void				print_map(char **map, t_tet *beg_5, int size_2);

#endif
