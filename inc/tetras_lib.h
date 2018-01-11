/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetras_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:29:18 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 13:48:35 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAS_LIB_H
# define TETRAS_LIB_H
# define TETRA_N_0 0xf000  // "1111 0000 0000 0000"
# define TETRA_H_0 1
# define TETRA_W_0 4
# define TETRA_N_1 0xe800  // "1110 1000 0000 0000"
# define TETRA_H_1 2
# define TETRA_W_1 3
# define TETRA_N_2 0xe400  // "1110 0100 0000 0000"
# define TETRA_H_2 2
# define TETRA_W_2 3
# define TETRA_N_3 0xe200  // "1110 0010 0000 0000"
# define TETRA_H_3 2
# define TETRA_W_3 3
# define TETRA_N_4 0x6c00  // "0110 1100 0000 0000"
# define TETRA_H_4 2
# define TETRA_W_4 3
# define TETRA_N_5 0xcc00  // "1100 1100 0000 0000"
# define TETRA_H_5 2
# define TETRA_W_5 2
# define TETRA_N_6 0xc600  // "1100 0110 0000 0000"
# define TETRA_H_6 2
# define TETRA_W_6 3
# define TETRA_N_7 0xc880  // "1100 1000 1000 0000"
# define TETRA_H_7 3
# define TETRA_W_7 2
# define TETRA_N_8 0xc440  // "1100 0100 0100 0000 "
# define TETRA_H_8 3
# define TETRA_W_8 2
# define TETRA_N_9 0x8e00  // "1000 1110 0000 0000"
# define TETRA_H_9 2
# define TETRA_W_9 3
# define TETRA_N_10 0x4e00  // "0100 1110 0000 0000"
# define TETRA_H_10 2
# define TETRA_W_10 3
# define TETRA_N_11 0x2e00  // "0010 1110 0000 0000"
# define TETRA_H_11 2
# define TETRA_W_11 3
# define TETRA_N_12 0x4c80  // "0100 1100 1000 0000"
# define TETRA_H_12 3
# define TETRA_W_12 2
# define TETRA_N_13 0x4c40  // "0100 1100 0100 0000"
# define TETRA_H_13 3
# define TETRA_W_13 2
# define TETRA_N_14 0x8c80  // "1000 1100 1000 0000"
# define TETRA_H_14 3
# define TETRA_W_14 2
# define TETRA_N_15 0x8c40 // "1000 1100 0100 0000"
# define TETRA_H_15 3
# define TETRA_W_15 2
# define TETRA_N_16 0x44c0  // "0100 0100 1100 0000"
# define TETRA_H_16 3
# define TETRA_W_16 2
# define TETRA_N_17 0x88c0  // "1000 1000 1100 0000"
# define TETRA_H_17 3
# define TETRA_W_17 2
# define TETRA_N_18 0x8888  // "1000 1000 1000 1000"
# define TETRA_H_18 4
# define TETRA_W_18 1
# define GRID_MAX 16
# define TETRAS_LIB_NB 19

typedef struct	s_tetra
{
	unsigned short int	n;
	unsigned char		w;
	unsigned char		h;
}				t_tetra;
#endif
