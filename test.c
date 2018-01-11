/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:39:33 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 19:20:21 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "test.h"
#include "tetras_lib.h"
#include "output.h"

int		test_params(int argc)
{
	return (argc != 2 ? 0 : 1);
}

int		test_source(char *file_name, t_tetra tetras_lib[], t_piece *pieces)
{
	int		fd;
	int		n;
	char	str[BUF_SIZE + 1];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		put_error_log("Error open file");
		return (-1);
	}
	n = read(fd, str, BUF_SIZE);
	str[n] = '\0';
	close(fd);

	return (fd);
}
