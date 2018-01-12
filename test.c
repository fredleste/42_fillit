/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:39:33 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/12 19:20:10 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/main.h"
#include "inc/test.h"
#include "inc/tetras_lib.h"
#include "inc/output.h"

int		test_params(int argc)
{
	return (argc != 2 ? 0 : 1);
}

int		put_file(char *file_name, char *str_pieces)
{
	int		fd;
	int		n;
	int		i;
	int		j;
	char	str[BUF_SIZE + 1];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		put_error_log("Error open file");
		return (-1);
	}
	n = read(fd, str, BUF_SIZE);
	str[n] = '\0';
	if (close(fd) == -1)
	{
		put_error_log("Error close file");
		return (-1);
	}
	if ((n + 1) % 21 != 0)
	{
		put_error_log("Error wrong file");
		return (-1);
	}
	i = 0;
	j = 0;
	while (i < n)
	{
		if (i % 5 == 0 || i % 21 == 0)
		{
			if (str[i] != '\n')
			{
				put_error_log("Error wrong tetra in file");
				return (-1);
			}
		}
		else
			str_pieces[j++] = str[i];
		i++;
	}
	str_pieces[j] = '\0';
	return ((n + 1) / 21);
}

int		put_binary(char *str)
{
	int				i;
	unsigned short	n;

	i = 0;
	n = 0x0000;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			n = n | (1 << (15 - i));
		}
		i++;
	}
	while ((n & 0x8888) == 0)
		n = n << 1;
	while ((n & 0xf000) == 0)
		n = n << 4;
	return (n);
}

int		put_pieces(char *str_pieces, t_tetra tetras_lib[], int pieces_nb,
	t_piece pieces[])
{
	int				i;
	int				j;
	char			str[16];
	unsigned short	bin_piece;

	while (i < pieces_nb)
	{
		while ()
		bin_piece = put_binary(str, tetras_lib);
		i = 0;
		while (n != tetras_lib[i].n)
			i++;
		if (i == TETRAS_LIB_NB)
		{
			put_error_log("Error wrong binary piece");
			return (-1);
		}
	}
	return (1);
}

int		test_source(char *file_name, t_tetra tetras_lib[], t_piece pieces[])
{
	int		i;
	int		pieces_nb;
	char	str_pieces[BUF_SIZE + 1];

	pieces_nb = put_file(file_name, str_pieces);
	i = 0;
	while (i < pieces_nb)
	{
		pieces[i].tetra = &(tetras_lib[i]);
		pieces[i].l = -1;
		pieces[i].c = -1;
		i++;
	}
	put_pieces(str_pieces, tetras_lib, pieces_nb, pieces);
	return (pieces_nb);
}
