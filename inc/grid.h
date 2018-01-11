/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:31:08 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 10:05:15 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# define C_POINT '.'
# define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int 	init_grid(char **grid, int grid_size);
int 	fill_grid(char **grid, int grid_size, int tetras_nb, t_bt **bt);
int 	write_grid(char **grid, int grid_size);
int 	del_grid(char **grid, int grid_size);
#endif
