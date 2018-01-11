/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:52:43 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 17:37:21 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "main.h"
#include "mock.h"

void	init_tetras_lib_mock(t_tetra tetras_lib[])
{
	tetras_lib[0].n = MOCK_TETRA_N_0;
	tetras_lib[0].h = MOCK_TETRA_H_0;
	tetras_lib[0].w = MOCK_TETRA_W_0;
	tetras_lib[1].n = MOCK_TETRA_N_1;
	tetras_lib[1].h = MOCK_TETRA_H_1;
	tetras_lib[1].w = MOCK_TETRA_W_1;
}

int		test_source_mock(char *file_name, t_tetra tetras_lib[],
	t_piece pieces[])
{
	int		i;

	i = 0;
	while (i < MOCK_PIECES_NB)
	{
		pieces[i].tetra = &(tetras_lib[i]);
		pieces[i].l = 4 * i;
		pieces[i].c = 4 * i;
		i++;
	}
	return (MOCK_PIECES_NB);
}

int		solver_mock(t_piece pieces[], int pieces_nb, t_list **p_bt)
{
	int		i;
	t_list	*new;
	t_list	*bt;
	
	if (!pieces_nb)
		return (-1);
	i = 0;
	while (i < pieces_nb)
	{
		new = ft_mba_lstnew((void const *)&(pieces[i]), sizeof(void *));
		if (!new)
		{
			put_error_log("Malloc error : ft_mba_new");
			return (-1);
		}
		if (!i)
			bt = new;
		else
		{
			new->next = bt;
		}
		i++;
	}
	*p_bt = new;
	return (MOCK_GRID_SIZE);
}
