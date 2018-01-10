/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:59:47 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/08 14:18:59 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include "main.h"

int	get_grid(short int *tetras, unsigned int tetras_length,
	char grid[GRID_MAX][GRID_MAX]);
#endif
