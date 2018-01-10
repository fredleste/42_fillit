/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:55:36 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/10 20:08:22 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOCK_H
# define MOCK_H
void 	init_tetras_lib_mock(t_tetra tetras_lib[]);
int		test_source_mock(char *file_name, t_tetra tetras_lib[],
	t_tetra **tetras);
#endif
