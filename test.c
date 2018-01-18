/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:39:33 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/18 14:57:55 by fleste-l         ###   ########.fr       */
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

int		put_binary(char *str, int tetras_lib[])
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
	while (i < TETRAS_LIB_NB && n != tetras_lib[i])
		i++;
	if (i == TETRAS_LIB_NB)
		return (-1);
	return (tetras_lib[i]);
}

int		test_source(char *file_name, int tetras_lib[], t_piece pieces[])
{
	int		i;
	int		p;
	int		pieces_nb;
	char	str[16];
	char	str_pieces[BUF_SIZE + 1];

	pieces_nb = put_file(file_name, str_pieces);
	p = 0;
	while (p < pieces_nb)
	{
		i = 0;
		while (i < 16)
		{
			str[i] = str_pieces[(p * 16) + i];
			i++;
		}
		str[i] = '\0';
		pieces[p].n = put_binary(str, tetras_lib);
		if (pieces[p].n == -1)
			return (-1);
		pieces[p].l = -1;
		pieces[p].c = -1;
		pieces[p].first = -1;
		pieces[p].last = -1;
		pieces[p].pos = -1;
		p++;
	}
	return (pieces_nb);
}
