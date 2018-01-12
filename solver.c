/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:51:32 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/12 12:14:47 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "solver.h"
#include "mock.h"

int		test_piece(t_piece *piece, int *pieces_nb)
{
	return (1);
}

int		solver_add_piece_bt(t_piece *piece, t_list **p_bt, unsigned char *bt_size)
{
	t_list	*new;
	t_list	*bt;
	
	bt = NULL;
	new = ft_mba_lstnew((void const *)piece, sizeof(void *));
	if (!new)
		return (0);
	if (!(*bt_size))
		bt = new;
	else
		new->next = bt;
	*p_bt = new;
	(*bt_size)++;
	return (1);
}

int		solver_add_piece_grid(t_piece *piece, unsigned short int grid[], unsigned char grid_size)
{
	
	return (1);
}

unsigned char	calc_grid_size(int pieces_nb)
{
	unsigned char		i;
	unsigned char		l;
	
	if (!pieces_nb)
		return (-1);
	i = 2;
	while (i * i <= pieces_nb)
		i++;
	l = 2 * i - 1;
	return (4 * pieces_nb < l * l ? l + 1 : l);
}

int		solver_move_piece(t_piece *pieces, unsigned char *bt_size, unsigned short int grid[], unsigned char grid_size)
{
	return (1);
}

int 	solver_write_grid(unsigned short int grid[], unsigned char grid_size)
{
	unsigned char		i;
	unsigned char		j;
	
	i = 0;
	while (i < grid_size)
	{
		j = 16;
		while (j > 16 - grid_size)
		{
			j--;
			ft_putchar((grid[i] >> j) & 1u ? '#' : '.');
		}
		ft_putchar('\n');
		i++;
	}
	return (1);
}

int		solver_init(unsigned short int grid[], unsigned char grid_size,
	t_list **p_bt, unsigned char *bt_size)
{
	unsigned char		i;
	unsigned char		j;
	
	i = 0;
	while (i < GRID_MAX)
	{
		grid[i] = (unsigned short int)GRID_ALL_ONE;
		if (i < grid_size)
		{
			j = 0;
			while (j < grid_size)
			{
				grid[i] &= ~(1u << (15 - j));
				j++;
			}
		}
		i++;
	}
	ft_lstdel(p_bt, NULL);
	*bt_size = 0;
	return (1);
}

int		solver(t_piece pieces[], int pieces_nb, t_list **p_bt)
{
	unsigned char		grid_size;
	unsigned short int	grid[GRID_MAX];
	unsigned char		bt_size;
	unsigned char		grid_ko;
	unsigned char		i;
	
	grid_size = calc_grid_size(pieces_nb);
	printf("grid_size init: %d\n", grid_size);
	bt_size = 0;
	while (bt_size != pieces_nb)
	{
		grid_ko = 0;
		solver_init(grid, grid_size, p_bt, &bt_size);
		solver_write_grid(grid, grid_size);
		while (bt_size != pieces_nb)
		{
			if (solver_add_piece_grid(&pieces[bt_size], grid, grid_size) == -1)
			{
				if (!solver_move_piece(pieces, &bt_size, grid, grid_size))
					grid_ko = 1;
			}
			else
				solver_add_piece_bt(&pieces[bt_size], p_bt, &bt_size);
			solver_write_grid(grid, grid_size);	
		}
		grid_size++;
		bt_size = pieces_nb;
	}
	return (grid_size);
}
