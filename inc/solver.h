/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleste-l <fleste-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:56:40 by fleste-l          #+#    #+#             */
/*   Updated: 2018/01/12 10:30:55 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# define GRID_ALL_ONE 0xFFFF

int				solver_add_piece(t_piece *piece, unsigned char *bt_size, t_list **p_bt);
unsigned char	calc_grid_size(int pieces_nb);
int 			solver_write_grid(unsigned short int grid[],
	unsigned char grid_size);
int		solver_init(unsigned short int grid[], unsigned char grid_size,
		t_list **p_bt, unsigned char *bt_size);
int				solver(t_piece *pieces, int pieces_nb, t_list **bt);
#endif
