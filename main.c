/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:02:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/22 19:30:44 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			put_error(int error)
{
	if (error)
		ft_putstr("error\n");
	else
		ft_putstr(FILLIT_USAGE);
	return (1);
}

int			put_error_log(const char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

static void	init_tetras_lib(int tetras_lib[])
{
	tetras_lib[0] = TETRA_N_0;
	tetras_lib[1] = TETRA_N_1;
	tetras_lib[2] = TETRA_N_2;
	tetras_lib[3] = TETRA_N_3;
	tetras_lib[4] = TETRA_N_4;
	tetras_lib[5] = TETRA_N_5;
	tetras_lib[6] = TETRA_N_6;
	tetras_lib[7] = TETRA_N_7;
	tetras_lib[8] = TETRA_N_8;
	tetras_lib[9] = TETRA_N_9;
	tetras_lib[10] = TETRA_N_10;
	tetras_lib[11] = TETRA_N_11;
	tetras_lib[12] = TETRA_N_12;
	tetras_lib[13] = TETRA_N_13;
	tetras_lib[14] = TETRA_N_14;
	tetras_lib[15] = TETRA_N_15;
	tetras_lib[16] = TETRA_N_16;
	tetras_lib[17] = TETRA_N_17;
	tetras_lib[18] = TETRA_N_18;
}

void		init_piece(t_piece *piece)
{
	piece->l = -1;
	piece->c = -1;
	piece->first = -1;
	piece->last = -1;
	piece->pos = -1;
}

int			main(int argc, char *argv[])
{
	int			tetras_lib[TETRAS_LIB_NB];
	t_piece		pieces[PIECES_NB_MAX];
	int			pieces_nb;
	int			grid_size;

	if (argc != 2)
		return (put_error(0));
	init_tetras_lib(tetras_lib);
	pieces_nb = test_source(argv[1], tetras_lib, pieces);
	if (pieces_nb < 1)
		return (put_error(1));
	grid_size = solver(pieces, pieces_nb);
	if (grid_size < 1)
		return (put_error(1));
	return (put_grid(pieces, pieces_nb, grid_size));
}
