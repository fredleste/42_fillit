/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:39:33 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/22 17:28:02 by fleste-l         ###   ########.fr       */
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

void	init_piece(t_piece pieces[], int p)
{
	int		x;

	pieces[p].l = -1;
	pieces[p].c = -1;
	pieces[p].first = -1;
	pieces[p].last = -1;
	pieces[p].pos = -1;
	x = 0;
	while (!(pieces[p].n & (1u << x)))
		x++;
	pieces[p].min = x - 1;
	pieces[p].h = 4 - (x / 4);
	x = 15;
	while (!(pieces[p].n & (1u << x)))
		x--;
	pieces[p].max = x;
	x = 0;
	while (!(pieces[p].n & (0x1111u << x)))
		x++;
	pieces[p].w = 4 - x;
}

void	put_piece(t_piece pieces[], int p)
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
		init_piece(pieces, p);
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
		put_piece(pieces, p);
		p++;
	}
	return (pieces_nb);
}
