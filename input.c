/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:39:33 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/26 15:30:32 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	put_binary(char *str, int tetras_lib[])
{
	int				i;
	unsigned short	n;

	i = 0;
	n = 0x0000;
	while (i < 16)
	{
		if (str[i] == '#')
			n = n | (1 << (15 - i));
		else if (str[i] != '.')
			return (0);
		i++;
	}
	if (!n)
		return (0);
	while ((n & 0x8888) == 0)
		n = n << 1;
	while ((n & 0xf000) == 0)
		n = n << 4;
	i = 0;
	while (i < TETRAS_LIB_NB && n != tetras_lib[i])
		i++;
	return (i == TETRAS_LIB_NB ? 0 : n);
}

static void	input_init_piece(t_piece *piece)
{
	int		n;

	init_piece(piece);
	n = piece->n;
	piece->h = 4;
	piece->w = 4;
	while (!(n & 0xF))
	{
		n >>= 4;
		piece->h--;
	}
	while (!(n & 0x1111))
	{
		n >>= 1;
		piece->w--;
	}
}

static void	put_piece(t_piece pieces[], int p)
{
	int		x;

	x = p;
	pieces[p].prev = -1;
	while (x && pieces[p].prev == -1)
	{
		x--;
		if (pieces[p].n == pieces[x].n)
		{
			ft_memcpy(&pieces[p], &pieces[x], sizeof(t_piece));
			pieces[p].prev = x;
		}
	}
	if (pieces[p].prev == -1)
		input_init_piece(&pieces[p]);
}

int			test_source(char *file_name, int tetras_lib[], t_piece pieces[])
{
	int		i;
	int		p;
	int		pieces_nb;
	char	str[16];
	char	str_pieces[BUF_SIZE];

	if (!(pieces_nb = put_file(file_name, str_pieces)))
		return (0);
	p = 0;
	while (p < pieces_nb)
	{
		i = 0;
		while (i < 16)
		{
			str[i] = str_pieces[(p * 16) + i];
			i++;
		}
		if (!(pieces[p].n = put_binary(str, tetras_lib)))
			return (0);
		put_piece(pieces, p);
		p++;
	}
	return (pieces_nb);
}
