/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:01:42 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/25 21:16:42 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_grid(t_piece *pieces, int pieces_nb, int grid_size)
{
	char	grid[GRID_OUTPUT_MAX + 1];
	int		i;
	int		j;
	int		k;

	ft_memset((void *)grid, C_POINT, (grid_size + 1) * grid_size);
	grid[(grid_size + 1) * grid_size] = '\0';
	i = 0;
	while (i++ < pieces_nb)
	{
		grid[(grid_size + 1) * (i + 1) - 1] = '\n';
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
	}
	ft_putstr(grid);
}
