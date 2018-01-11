/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:39:33 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 17:04:28 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		test_params(int argc)
{
	argc != 2 ? return (0) : return (1);
}

int		test_source(char *file_name, t_tetra tetras_lib[], t_piece *pieces)
{
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	//n = 1;
	///n = read(fd, buf, BUF_SIZE);
	//buf[n] = '\0';
	//write(1, buf, n);
	//close(fd);

	return (0);
}
