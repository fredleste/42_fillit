/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:01:42 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 19:05:27 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "output.h"
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

int		put_grid(t_list **bt, int tetras_nb, int grid_size)
{
	char	**grid;

	if (!bt || !*bt || !tetras_nb || !grid_size)
		return (put_error(1));
	grid = NULL;
	if (!init_grid(grid, grid_size))
		return (put_error_log("Malloc error : init_grid"));
	if (!fill_grid(grid, grid_size, tetras_nb, bt))
		return (put_error_log("Error in fill_grid"));
	if (!write_grid(grid, grid_size))
		return (put_error_log("Error in write_grid"));
	if (!del_grid(grid, grid_size))
		return (put_error_log("Error in del_grid"));
	return (1);
}
