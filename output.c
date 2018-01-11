/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:01:42 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 17:29:39 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "main.h"
#include "grid.h"

int		put_error(int error)
{
	if (error)
		ft_putstr("error\n");
	else
		ft_putstr(FILLIT_USAGE);
	return (1);
}

int		put_error_log(const char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

int		put_grid(t_list *bt, int pieces_nb, int grid_size)
{
	char	**grid;
	
	if (!pieces_nb || !grid_size)
		return (put_error(1));
	grid = NULL;
	put_error_log("---------------------\n------------------ INIT GRID\n\n");
	if (!(grid = init_grid(grid_size)))
		return (put_error_log("Malloc error : init_grid"));
		put_error_log("---------------------\n------------------ FILL GRID\n\n");
	if (!fill_grid(grid, grid_size, pieces_nb, bt))
		return (put_error_log("Error in fill_grid"));
		put_error_log("---------------------\n------------------ WRITE GRID\n\n");
	if (!write_grid(grid, grid_size))
		return (put_error_log("Error in write_grid"));
		put_error_log("---------------------\n------------------ DEL GRID\n\n");
	if (!del_grid(grid, grid_size))
		return (put_error_log("Error in del_grid"));
	return (1);
}
