/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:51:32 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/25 17:55:46 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	calc_grid_size(int pieces_nb)
{
	int		i;

	if (!pieces_nb)
		return (-1);
	i = 2;
	while (i * i < 4 * pieces_nb)
		i++;
	return (i);
}

/*
int		solver_write_grid(int grid[], int grid_size)
{
	int		i;
	int		j;

	//printf("---*---*---*---* %d\n", grid_size);
	ft_putstr("---*---*---*---* ");
	ft_putnbr(grid_size);
	ft_putstr(" \n");
	i = 0;
	while (i < grid_size)
	{
	   ft_putnbr(grid[i]);
	   ft_putstr(" ");
	   i++;
	}
	ft_putchar('\n');
	i = 0;
	while (i < grid_size)
	{
		j = 16;
		while (j > 16 - grid_size)
		{
			j--;
			ft_putchar((grid[i] >> j) & 1 ? '#' : '.');
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr("---*---*---*---*\n");
	return (1);
}
*/

static int	solver_init(int grid[], int grid_size, t_piece *pieces,
	int *p_bt_size)
{
	int		i;

	grid[0] = GRID_ALL_ONE;
	i = grid_size;
	while (--i > -1)
		grid[0] &= ~(1 << (15 - i));
	i = 0;
	while (++i < GRID_MAX)
		grid[i] = grid[0];
	i = *p_bt_size;
	while (i--)
	{
		pieces[i].l = -1;
		pieces[i].c = -1;
		pieces[i].pos = -1;
		pieces[i].last = -1;
	}
	*p_bt_size = 0;
	return (1);
}

int			solver(t_piece pieces[], int pieces_nb)
{
	int		grid_size;
	int		grid[GRID_MAX];
	int		bt_size;
	int		grid_ok;

	grid_size = calc_grid_size(pieces_nb);
	bt_size = 0;
	while (bt_size < pieces_nb)
	{
		grid_ok = 1;
		solver_init(grid, grid_size, pieces, &bt_size);
		while (grid_ok && bt_size != pieces_nb)
			grid_ok = solver_add_piece_grid(pieces, &bt_size, grid, grid_size);
		if (bt_size < pieces_nb)
			grid_size++;
	}
	return (grid_size);
}
