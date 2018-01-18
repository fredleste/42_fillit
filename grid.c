/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:31:38 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/18 19:17:29 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "main.h"
#include "grid.h"
#include "test.h"

char	**init_grid(int grid_size)
{
	int		l;
	int		c;
	char			**grid;

	grid = NULL;
	if (!(grid = (char **)malloc(grid_size * sizeof(char *))))
		return (NULL);
	l = 0;
	while (l < grid_size)
	{
		if (!(grid[l] = (char *)malloc(grid_size * sizeof(char))))
		{
			del_grid(grid, l - 1);
			return (0);
		}
		c = 0;
		while (c < grid_size)
		{
			grid[l][c] = C_POINT;
			c++;
		}
		l++;
	}
	return (grid);
}

void	set_tetra_grid(char **grid, t_piece *piece, char letter)
{
	int		i;
	int		l;
	int		c;
	
	i = piece->max;
	l = piece->l;
	c = 15 + piece->c;
	printf("-- set_tetra_grid tetra:%d max:%d min:%d piece->l:%d piece->c:%d\n", piece->n, piece->max, piece->min, piece->l, piece->c);
	while (i > piece->min)
	{
		if (piece->n & (1 << i))
		{
			printf("tetra:%d i:%d (l):%d (c - i):%d\n", piece->n, i, l, c - i);
			grid[l][c - i] = letter;
		}
		if (!(i % 4))
		{
			l++;
			c -= 4;
		}
		i--;
	}
}

int		fill_grid(char **grid, t_piece *pieces, int pieces_nb)
{
	int		i;
	char	c;

	i = 0;
	c = 'A';
	//printf("-- set_grid grid_size: %d pieces_nb:%d\n", grid_size, pieces_nb);
	while (i < pieces_nb)
	{
		//printf("grid_size: %d pieces_nb:%d i:%d\n", grid_size, pieces_nb, i);
		set_tetra_grid(grid, &pieces[i], c);
		i++;
		c++;
	}
	return (1);
}

int		write_grid(char **grid, int grid_size)
{
	int		l;
	int		c;

	l = 0;
	while (l < grid_size)
	{
		c = 0;
		while (c < grid_size)
		{
			ft_putchar(grid[l][c]);
			c++;
		}
		ft_putchar('\n');
		l++;
	}
	return (1);
}

int		del_grid(char **grid, int grid_size)
{
	int		l;

	l = 0;
	while (l < grid_size)
	{
		free(grid[l]);
		grid[l++] = NULL;
	}
	free(grid);
	grid = NULL;
	return (1);
}
