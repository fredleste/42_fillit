/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:31:08 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/18 14:13:52 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# define C_POINT '.'

char	**init_grid(int grid_size);
int		fill_grid(char **grid, t_piece *pieces, int pieces_nb);
void	set_tetra_grid(char **grid, t_piece *piece, char c);
int		write_grid(char **grid, int grid_size);
int		del_grid(char **grid, int grid_size);
#endif
