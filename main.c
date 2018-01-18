/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:02:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/18 14:20:44 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "tetras_lib.h"
#include "test.h"
#include "solver.h"
#include "output.h"

int		main(int argc, char *argv[])
{
	int			tetras_lib[TETRAS_LIB_NB];
	t_piece		pieces[PIECES_NB_MAX];
	int			pieces_nb;
	int			grid_size;

	if (!test_params(argc))
		return (put_error(0));
	init_tetras_lib(tetras_lib);
	pieces_nb = test_source(argv[1], tetras_lib, pieces);
	if (pieces_nb == -1)
		return (put_error(1));
	grid_size = solver(pieces, pieces_nb);
	if (grid_size == -1)
		return (put_error(1));
	return (put_grid(pieces, pieces_nb, grid_size));
}
