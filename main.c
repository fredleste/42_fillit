/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:02:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/08 18:10:11 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int argc, char *argv[])
{
	t_tetra			tetras_lib[TETRAS_LIB_NB];
	short int		*tetras;
	int				tetras_length;
	char			grid[GRID_MAX][GRID_MAX];
	int				grid_length;

	if (!test_params(argc))
		return (put_error(0));
	init_tetras_lib(tetras_lib);
	tetras = NULL;
	tetras_length = test_source(argv[1], tetras_lib, tetras);
	if (tetras_length == -1)
		return (put_error(1));
	grid_length = get_grid(tetras, tetras_length, grid);
	if (grid_length == -1)
		return (put_error(1));
	put_grid(grid, grid_length);
	return (0);
}
