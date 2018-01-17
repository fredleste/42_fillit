/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:39:33 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/17 17:32:50 by fleste-l         ###   ########.fr       */
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

int		put_file(char *file_name, char *str_pieces)
{
	int		n;
	int		i;
	int		j;
	char	buf[BUF_SIZE + 1];

	i = open(file_name, O_RDONLY);
	if (i == -1)
		return (-1);
	n = read(i, buf, BUF_SIZE);
	buf[n] = '\0';
	if (close(i) == -1)
		return (-1);
	if ((n + 1) % 21 != 0)
		return (-1);
	i = 0;
	j = 0;
	while (i < n)
	{
		if ((i + 1 - i / 21) % 5 == 0 || (i + 1) % 21 == 0)
		{
			if (buf[i] != '\n')
				return (-1);
		}
		else
			str_pieces[j++] = buf[i];
		i++;
	}
	str_pieces[j] = '\0';
	return ((n + 1) / 21);
}

t_tetra	*put_binary(char *str, t_tetra tetras_lib[])
{
	int				i;
	unsigned short	n;

	i = 0;
	n = 0x0000;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			n = n | (1 << (15 - i));
		else if (str[i] != '.')
			return (NULL);
		i++;
	}
	while ((n & 0x8888) == 0)
		n = n << 1;
	while ((n & 0xf000) == 0)
		n = n << 4;
	i = 0;
	while (i < TETRAS_LIB_NB && n != tetras_lib[i].n)
		i++;
	if (i == TETRAS_LIB_NB)
		return (NULL);
	return (&(tetras_lib[i]));
}

int		test_source(char *file_name, t_tetra tetras_lib[], t_piece pieces[])
{
	int		i;
	int		n;
	int		pieces_nb;
	char	str[16];
	char	str_pieces[BUF_SIZE + 1];

	pieces_nb = put_file(file_name, str_pieces);
	n = 0;
	while (n < pieces_nb)
	{
		i = 0;
		while (i < 16)
		{
			str[i] = str_pieces[(n * 16) + i];
			i++;
		}
		str[i] = '\0';
		pieces[n].tetra = put_binary(str, tetras_lib);
		if (pieces[n].tetra == NULL)
			return (-1);
		pieces[n].l = -1;
		pieces[n].c = -1;
		n++;
	}
	return (pieces_nb);
}
