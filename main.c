/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:02:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 08:25:06 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int argc, char *argv[])
{
	t_tetra			tetras_lib[TETRAS_LIB_NB];
	t_tetra			**tetras;
	int				tetras_nb;
	t_bt			**bt;
	int				grid_size;

	if (!test_params(argc))
		return (put_error(0));
	init_tetras_lib(tetras_lib);
	tetras = NULL;
	tetras_nb = test_source(argv[1], tetras_lib, tetras);
	if (tetras_nb == -1)
		return (put_error(1));
	bt = NULL;
	grid_size = solver(tetras, tetras_nb, bt);
	if (grid_size == -1)
		return (put_error(1));
	put_grid(bt, tetras_nb, grid_size);
	return (0);
}
