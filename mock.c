/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:52:43 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/10 20:29:28 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "mock.h"

void	init_tetras_lib_mock(t_tetra tetras_lib[])
{
	tetras_lib[0].n = 0xf000;
	tetras_lib[1].n = 0x888;
}

int		test_source_mock(char *file_name, t_tetra tetras_lib[],
	t_tetra **tetras)
{
	int		i;
	int		j;
		
	if (!(tetras = (t_tetra **)malloc(2 * sizeof(t_tetra *))))
	{
		put_error_log("malloc echec - mock.c - l 27");
		return (-1);
	}
	i = 0;
	while (i < 2)
	{
		if (!(tetras[i] = (t_tetra *)malloc(sizeof(t_tetra))))
		{
			j = i - 1;
			while (j > -1)
				free(tetras[j--]);
			free(tetras);
			put_error_log("malloc echec - mock.c - l 38");
			return (-1);
		}
		tetras[i] = &(tetras_lib[i]);
		i++;
	}
	return (0);
}
