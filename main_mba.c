/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mba.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:02:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/16 16:41:13 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "mock.h"
#include "test.h"
#include "solver.h"
#include "output.h"

int		main(int argc, char *argv[])
{
	t_tetra			tetras_lib[TETRAS_LIB_NB];
	t_piece			pieces[PIECES_NB_MAX];
	int				pieces_nb;
	int				grid_size;
	
	//put_error_log("-------------------------------\n------------------ INIALISATION\n\n");
	if (!test_params_mock(argc))
		return (put_error(0));
	//put_error_log("-------------------------------\n------------------ INIT TETRAS\n\n");
	init_tetras_lib_mock(tetras_lib);
	//put_error_log("-------------------------------\n------------------ TEST SOURCE\n\n");
	pieces_nb = test_source_mock(argv[1], tetras_lib, pieces);
	if (pieces_nb == -1)
		return (put_error(1));
	//printf("nb_pieces : %d\n", pieces_nb);
	//put_error_log("-------------------------------\n------------------ SOLVER\n\n");
	grid_size = solver(pieces, pieces_nb);
	if (grid_size == -1)
		return (put_error(1));
	//put_error_log("-------------------------------\n------------------ PUT GRID\n\n");
	return	(put_grid(pieces, pieces_nb, grid_size));
}
