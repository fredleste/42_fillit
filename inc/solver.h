/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleste-l <fleste-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:56:40 by fleste-l          #+#    #+#             */
/*   Updated: 2018/01/17 14:14:21 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# define GRID_ALL_ONE 0xFFFF

int		test_piece_grid(t_piece *piece, char l, char c,
	unsigned short int grid[]);
int		get_last_position(t_piece *piece, unsigned short int grid[],
	unsigned char grid_size);
int		get_next_position(t_piece *piece, unsigned short int grid[],
	unsigned char grid_size);
int		solver_add_piece_grid(t_piece *piece, unsigned char *bt_size,
	unsigned short int grid[], unsigned char grid_size);
unsigned char	calc_grid_size(int pieces_nb);
int		solver_write_grid(unsigned short int grid[],
	unsigned char grid_size);
int		solver_init(unsigned short int grid[], unsigned char grid_size,
	t_piece *pieces, unsigned char *bt_size);
int		solver(t_piece *pieces, int pieces_nb);
#endif
