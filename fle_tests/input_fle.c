/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:39:33 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/30 16:32:08 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <time.h>

static int	put_binary(char *str, int tetras_lib[])
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
			return (-1);
		i++;
	}
	while ((n & 0x8888) == 0)
		n = n << 1;
	while ((n & 0xf000) == 0)
		n = n << 4;
	i = 0;
	while (i < TETRAS_LIB_NB && n != tetras_lib[i])
		i++;
	return (i == TETRAS_LIB_NB ? -1 : n);
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
	char	str_pieces[BUF_SIZE + 1];
	long	clk_tck = CLOCKS_PER_SEC;
	clock_t t1, t2;

	t1 = clock();
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
		put_piece(pieces, p);
		p++;
	}
	t2 = clock();
	printf("Nb ticks/seconde = %ld, Nb ticks depart : %ld, Nb ticks final : %ld\n", clk_tck, t1, t2);
	printf("Temps consomme (s) : %lf \n", (double)(t2 - t1) / (double)clk_tck);
	return (pieces_nb);
}
