/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:40:08 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/08 18:01:08 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include "tetras_lib.h"

int test_params(int argc);
int test_source(char *file_name, t_tetra tetras_lib[TETRAS_LIB_NB],
	short int *tetras);
#endif
