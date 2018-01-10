/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetras_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:29:18 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/10 17:41:08 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAS_LIB_H
# define TETRAS_LIB_H
# define TETRA_0 "11111"
# define TETRA_1 "11101"
# define TETRA_2 "111001"
# define TETRA_3 "1110001"
# define TETRA_4 "011011"
# define TETRA_5 "110011"
# define TETRA_6 "1100011"
# define TETRA_7 "110010001"
# define TETRA_8 "1100010001"
# define TETRA_9 "1000111"
# define TETRA_10 "0100111"
# define TETRA_11 "0010111"
# define TETRA_12 "010011001"
# define TETRA_13 "0100110001"
# define TETRA_14 "100011001"
# define TETRA_15 "1000110001"
# define TETRA_16 "0100010011"
# define TETRA_17 "1000100011"
# define TETRA_18 "10000100010001"
# define GRID_MAX 16
# define TETRAS_LIB_NB 19

typedef struct	s_tetra
{
	char				bin[GRID_MAX];
	unsigned short int	n;
}				t_tetra;
#endif
