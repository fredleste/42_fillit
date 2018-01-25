/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:01:42 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/25 18:05:51 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	del_grid(char **grid, int grid_size)
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
}

char		**init_grid(int grid_size)
{
	int		l;
	int		c;
	char	**grid;

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

static void	fill_grid(char **grid, t_piece *pieces, int pieces_nb)
{
	int		i;
	int		j;
	int		l;
	int		c;

	i = 0;
	while (i < pieces_nb)
	{
		j = pieces[i].max;
		l = pieces[i].l;
		c = 15 + pieces[i].c;
		while (j > pieces[i].min)
		{
			if (pieces[i].n & (1 << j))
				grid[l][c - j] = 'A' + i;
			if (!(j % 4))
			{
				l++;
				c -= 4;
			}
			j--;
		}
		i++;
	}
}

static void	write_grid(char **grid, int grid_size)
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
}

int			put_grid(t_piece *pieces, int pieces_nb, int grid_size)
{
	char	**grid;

	grid = NULL;
	if (!(grid = init_grid(grid_size)))
		return (put_error(1));
	fill_grid(grid, pieces, pieces_nb);
	write_grid(grid, grid_size);
	del_grid(grid, grid_size);
	return (0);
}
