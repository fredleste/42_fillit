/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:39:33 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/19 18:25:19 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "test.h"
#include "tetras_lib.h"
#include "output.h"

int		read_file(char *file_name, char buf[])
{
	int		n;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		put_error_log("Error open file\n");
		return (0);
	}
	n = read(fd, buf, BUF_SIZE);
	if (close(fd) == -1)
	{
		put_error_log("Error close file\n");
		return (0);
	}
	return (n);
}

int		put_file(char *file_name , char *str_pieces)
{
	int		n;
	int		i;
	int		j;
	char	buf[BUF_SIZE + 1];

	n = read_file(file_name, buf);
	if ((n + 1) % 21 != 0)
	{
		put_error_log("Error wrong file\n");
		return (-1);
	}
	i = 0;
	j = 0;
	while (i < n)
	{
		if ((i + 1 - i / 21) % 5 == 0 || (i + 1) % 21 == 0)
		{
			if (buf[i] != '\n')
			{
				put_error_log("Error wrong file format\n");
				return (-1);
			}
		}
		else if (buf[i] != '.' && buf[i] != '#')
		{
			put_error_log("Error wrong piece format\n");
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

void	init_pieces(t_piece pieces[], int pieces_nb)
{
	int		i;

	i = 0;
	while (i < pieces_nb)
	{
		pieces[i].l = -1;
		pieces[i].c = -1;
		pieces[i].first = -1;
		pieces[i].last = -1;
		pieces[i].pos = -1;
		i++;
	}
}

void	put_pieces(t_piece pieces[], int pieces_nb)
{
	int		i;
	int		x;

	i = 0;
	while (i < pieces_nb)
	{
		x = i;
		pieces[i].prev = -1;
		while (x && pieces[i].prev == -1)
		{
			x--;
			if (pieces[i].n == pieces[x].n)
				pieces[i].prev = x;
		}
		if (pieces[i].prev == -1)
		{
			x = 0;
			while (!(pieces[i].n & (1u << x)))
				x++;
			pieces[i].min = x - 1;
			pieces[i].h = 4 - (x / 4);
			x = 15;
			while (!(pieces[i].n & (1u << x)))
				x--;
			pieces[i].max = x;
			x = 0;
			while (!(pieces[i].n & (0x1111u << x)))
				x++;
			pieces[i].w = 4 - x;
		}
		else
		{
			pieces[i].min = pieces[x].min;
			pieces[i].max = pieces[x].max;
			pieces[i].h = pieces[x].h;
			pieces[i].w = pieces[x].w;
		}
		i++;
	}
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
		{
			put_error_log("Error wrong binary tetra\n");
			return (-1);
		}
		/*i = p;
		while (i && pieces[i - 1].n != pieces[p].n)
			i--;
		pieces[p].prev = pieces[i - 1].n == pieces[p].n ? i - 1 : -1;*/
		p++;
	}
	init_pieces(pieces, pieces_nb);
	put_pieces(pieces, pieces_nb);
	return (pieces_nb);
}
