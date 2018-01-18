/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:52:43 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/18 19:10:44 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "main.h"
#include "mock.h"
#include "output.h"
#include "tetras_lib.h"

void	init_tetras_lib_mock(int tetras_lib[])
{
	tetras_lib[0] = TETRA_N_0;
	tetras_lib[1] = TETRA_N_18;
	tetras_lib[2] = TETRA_N_11;
	/*
	tetras_lib[3] = TETRA_N_0;
	tetras_lib[4] = TETRA_N_0;
	tetras_lib[5] = TETRA_N_0;
	tetras_lib[6] = TETRA_N_18;
	*/
}

int		test_params_mock(int argc)
{
	return (1);
}

int		test_source_mock(char *file_name, int tetras_lib[],
	t_piece pieces[])
{
	int		i;

	i = 0;
	while (i < MOCK_TETRAS_NB)
	{
		pieces[i].n = tetras_lib[i];
		pieces[i].l = -1;
		pieces[i].c = -1;
		pieces[i].first = -1;
		pieces[i].last = -1;
		pieces[i].pos = -1;
		pieces[i].prev = -1;
		i++;
	}
	pieces[0].h = 1;
	pieces[0].w = 4;
	pieces[0].max = 15;
	pieces[0].min = 11;
	pieces[1].h = 4;
	pieces[1].w = 1;
	pieces[1].max = 15;
	pieces[1].min = 2;
	pieces[2].h = 2;
	pieces[2].w = 3;
	pieces[2].max = 13;
	pieces[2].min = 8;
	pieces[3].n = tetras_lib[0];
	pieces[3].l = -1;
	pieces[3].c = -1;
	pieces[3].first = -1;
	pieces[3].last = -1;
	pieces[3].pos = -1;
	pieces[3].prev = 0;
	pieces[3].h = pieces[0].h;
	pieces[3].w = pieces[0].w;
	pieces[3].max = pieces[0].max;
	pieces[3].min = pieces[0].min;
	return (MOCK_PIECES_NB);
}

int		solver_mock(t_piece pieces[], int pieces_nb)
{
	return (MOCK_GRID_SIZE);
}
