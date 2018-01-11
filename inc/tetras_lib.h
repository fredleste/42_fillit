/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetras_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:29:18 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 11:57:28 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAS_LIB_H
# define TETRAS_LIB_H
# define TETRA_0  //"1111"
# define TETRA_1 "1110 1"
# define TETRA_2 "1110 01"
# define TETRA_3 "1110 001"
# define TETRA_4 "01101 1"
# define TETRA_5 "1100 11"
# define TETRA_6 "1100011"
# define TETRA_7 "11001 0001"
# define TETRA_8 "11000 10001 "
# define TETRA_9 "1000 111"
# define TETRA_10 "0100 111"
# define TETRA_11 "0010 111"
# define TETRA_12 "01001 1001"
# define TETRA_13 "0100110001"
# define TETRA_14 "100011001"
# define TETRA_15 "1000110001"
# define TETRA_16 "0100010011"
# define TETRA_17 "1000100011"
# define TETRA_18 "1000100010001000"
# define GRID_MAX 16
# define TETRAS_LIB_NB 19

typedef struct	s_tetra
{
	unsigned short int	n;
	char				w;
	char				h;
}				t_tetra;
#endif
