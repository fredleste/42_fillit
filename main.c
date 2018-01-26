/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:02:11 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/26 16:41:02 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	put_error(int error)
{
	if (error)
		ft_putstr("error\n");
	else
		ft_putstr(FILLIT_USAGE);
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

static void	grid_init(char grid[], int grid_size)
{
	int		i;

	ft_memset((void *)grid, C_POINT, (grid_size + 1) * grid_size);
	grid[(grid_size + 1) * grid_size] = '\0';
	i = 1;
	while (i <= grid_size)
	{
		grid[(grid_size + 1) * i - 1] = '\n';
		i++;
	}
}

static void	put_grid(t_piece *pieces, int pieces_nb, int grid_size)
{
	char	grid[GRID_OUTPUT_MAX + 1];
	int		i;
	int		j;
	int		k;

	grid_init(grid, grid_size);
	i = 0;
	while (i < pieces_nb)
	{
		j = 15;
		k = 4;
		while (k)
		{
			if (pieces[i].n & (1u << j))
			{
				grid[(grid_size + 1) * (pieces[i].l + (15 - j) / 4)
				+ pieces[i].c + (15 - j) % 4] = 'A' + i;
				k--;
			}
			j--;
		}
		i++;
	}
	ft_putstr(grid);
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
	if (!(pieces_nb = test_source(argv[1], tetras_lib, pieces)))
		return (put_error(1));
	grid_size = solver(pieces, pieces_nb);
	put_grid(pieces, pieces_nb, grid_size);
	return (0);
}
