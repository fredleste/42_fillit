/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:02:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 19:26:08 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tetras_lib.h"
#include "test.h"
#include "solver.h"
#include "output.h"

int		main(int argc, char *argv[])
{
	t_tetra			tetras_lib[TETRAS_LIB_NB];
	t_piece			pieces[PIECES_NB_MAX];
	int				pieces_nb;
	t_list			*bt;
	int				grid_size;

	if (!test_params(argc))
		return (put_error(0));
	init_tetras_lib(tetras_lib);
	pieces_nb = test_source(argv[1], tetras_lib, pieces);
	if (pieces_nb == -1)
		return (put_error(1));
	bt = NULL;
	grid_size = solver(pieces, pieces_nb, bt);
	if (grid_size == -1)
		return (put_error(1));
	return (put_grid(bt, pieces_nb, grid_size));
}
