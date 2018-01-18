/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleste-l <fleste-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:56:40 by fleste-l          #+#    #+#             */
/*   Updated: 2018/01/18 14:17:13 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# define GRID_ALL_ONE 0xFFFF

void	solver_init_piece(t_piece *piece);
int		test_piece_grid(t_piece *piece, int l, int c, int grid[]);
int		place_piece_grid(t_piece *piece, int grid[]);
int		remove_piece_grid(t_piece *piece, int grid[]);
int		get_last_position(t_piece *piece, int grid[], int grid_size);
int		get_next_position(t_piece *piece, int grid[], int grid_size);
int		solver_add_piece_grid(t_piece *piece, int *bt_size, int grid[],
	int grid_size);
int		calc_grid_size(int pieces_nb);
int		solver_write_grid(int grid[], int grid_size);
int		solver_init(int grid[], int grid_size, t_piece *pieces, int *bt_size);
int		solver(t_piece *pieces, int pieces_nb);
#endif
