/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:03:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/19 21:38:47 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# define GRID_MAX 16
# define TETRAS_LIB_NB 19
# define PIECES_NB_MAX 26
# define FILLIT_USAGE "usage: ./fillit source_file\n"
# define BUF_SIZE 545
# define GRID_ALL_ONE 0xFFFF
# define TETRA_N_0 0xf000
# define TETRA_N_1 0xe800
# define TETRA_N_2 0xe400
# define TETRA_N_3 0xe200
# define TETRA_N_4 0x6c00
# define TETRA_N_5 0xcc00
# define TETRA_N_6 0xc600
# define TETRA_N_7 0xc880
# define TETRA_N_8 0xc440
# define TETRA_N_9 0x8e00
# define TETRA_N_10 0x4e00
# define TETRA_N_11 0x2e00
# define TETRA_N_12 0x4c80
# define TETRA_N_13 0x4c40
# define TETRA_N_14 0x8c80
# define TETRA_N_15 0x8c40
# define TETRA_N_16 0x44c0
# define TETRA_N_17 0x88c0
# define TETRA_N_18 0x8888
# define C_POINT '.'

typedef struct	s_piece
{
	int			n;
	int			min;
	int			max;
	int			h;
	int			w;
	int			l;
	int			c;
	int			first;
	int			last;
	int			pos;
	int			prev;
}				t_piece;
int				put_error(int error);
int				put_error_log(const char *str);
int				test_source(char *file_name, int tetras_lib[],
	t_piece pieces[]);
void			init_piece(t_piece *piece);
int				solver_add_piece_grid(t_piece *piece, int *bt_size, int grid[],
	int grid_size);
int				solver(t_piece *pieces, int pieces_nb);
int				put_grid(t_piece *pieces, int pieces_nb, int grid_size);
#endif
