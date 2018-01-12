/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:31:08 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/12 14:54:06 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# define C_POINT '.'
# define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

char 	**init_grid(int grid_size);
int 	fill_grid(char **grid, int tetras_nb, t_list *bt);
void 	set_tetra_grid(char **grid, t_piece *piece, char c);   
int 	write_grid(char **grid, int grid_size);
int 	del_grid(char **grid, int grid_size);
#endif
