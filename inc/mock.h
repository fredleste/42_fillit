/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:55:36 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 13:10:29 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOCK_H
# define MOCK_H
# define MOCK_TETRA_N_0 0xf000
# define MOCK_TETRA_H_0 1
# define MOCK_TETRA_W_0 4
# define MOCK_TETRA_N_1 0x8888
# define MOCK_TETRA_H_1 4
# define MOCK_TETRA_W_1 1
# define MOCK_TETRAS_NB 2
# define MOCK_PIECES_NB 2
# define MOCK_GRID_SIZE MOCK_PIECES_NB * 4

void 	init_tetras_lib_mock(t_tetra tetras_lib[]);
int		test_source_mock(char *file_name, t_tetra tetras_lib[],
	t_piece pieces[]);
int		solver_mock(t_piece pieces[], int pieces_nb, t_list **bt);
#endif
