/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:01:42 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/08 18:15:41 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"

int		put_error(int error)
{
	if (error)
		ft_putstr("error\n");
	else
		ft_putstr(FILLIT_USAGE);
	return (1);
}

void	put_grid(char grid[GRID_MAX][GRID_MAX], int grid_length)
{
	ft_putstr("put_grid\n");
}
