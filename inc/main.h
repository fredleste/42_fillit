/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:03:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 15:14:31 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include "libft.h"
# include "tetras_lib.h"
# define GRID_MAX 16
# define TETRAS_LIB_NB 19
# define PIECES_NB_MAX 26
# define FILLIT_USAGE "usage: ./fillit source_file\n"

typedef struct	s_piece
{
	t_tetra			*tetra;
	unsigned char 	l;
	unsigned char 	c;
}				t_piece;
void 	init_tetras_lib	(t_tetra tetras_lib[]);
int 	test_params(int argc);
int 	test_source(char *file_name, t_tetra tetras_lib[], t_piece pieces[]);
int		solver(t_piece pieces[], int pieces_nb, t_list *bt);
int		put_error(int error);
int		put_error_log(const char *str);
int		put_grid(t_list *bt, int pieces_nb, int grid_size);
#endif
