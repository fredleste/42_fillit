/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:51:32 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/17 14:10:08 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "solver.h"
#include "mock.h"

/*
int		solver_add_piece_bt(t_piece *piece, t_list **p_bt, unsigned char *bt_size)
{
	t_list	*new;
	t_list	*bt;

	bt = NULL;
	new = ft_mba_lstnew((void const *)piece, sizeof(void *));
	if (!new)
		return (0);
	if (!(*bt_size))
		bt = new;
	else
		new->next = bt;
	*p_bt = new;
	(*bt_size)++;
	return (1);
}
*/

void	solver_pieces_init(t_piece *pieces,  int pieces_nb)
{

}

int		test_piece_grid(t_piece *piece, char l, char c, unsigned short int grid[])
{
	int		max;
	int		i;
	int		t;
	int		ok;
	int		ko;

	max = (piece->tetra->h - 1) * 4 + piece->tetra->w;
	//printf("-- test_piece_grid n:%d h:%d w:%d l:%d c:%d\n", piece->tetra->n, piece->tetra->h, piece->tetra->w, l, c);
	i = 0;
	t = 4;
	ok = 0;
	ko = 0;
	while (i < max && t && !ko)
	{
		if (piece->tetra->n & (1u << (15 - i)))
		{
			t--;
			if (!(grid[l + i / 4]
				& (1u << (15 - c - i % 4))))
				ok++;
			else
				ko = 1;
			//printf("i:%d ok:%d ko: %d l+im4:%d dec:%d\n", i, ok, ko, l + i / 4, 15 - c - i % 4);
		}
		i++;
	}
	if (ok != 4)
		return (0);
	piece->first = 16 * l + c;
	return (1);
}

int		place_piece_grid(t_piece *piece, unsigned short int grid[])
{
	int		max;
	int		i;
	int		t;

	//printf("-- place_piece_grid n:%d l:%d c:%d\n", piece->tetra->n, piece->l, piece->c);
	max = (piece->tetra->h - 1) * 4 + piece->tetra->w;
	i = 0;
	t = 4;
	while (i < max && t)
	{
		//printf("i:%d max:%d\n", i, max);
		if (piece->tetra->n & (1u << (15 - i)))
		{
			t--;
			//printf("indice:%d rang:%d\n", piece->l + i / 4, 15 - piece->c - i);
			grid[piece->l + i / 4] |= 1UL << (15 - piece->c - i % 4);
		}
		i++;
	}
	return (1);
}

int		get_last_position(t_piece *piece, unsigned short int grid[],
	unsigned char grid_size)
{
	char	l;
	char	c;

	//printf("\n-- get_last_position %d\n", piece->tetra->n);
	l = grid_size - piece->tetra->h;
	c = grid_size - piece->tetra->w;
	//printf("grid_size:%d h:%d w:%d l:%d c:%d\n", grid_size, piece->tetra->h, piece->tetra->w, l, c);
	while (l > -1 && c > -1)
	{
		//printf("test l:%d c:%d\n", l, c);
		if (piece->first >= 16 * l + c)
		{
			//printf("return -1 l:%d c:%d first:%d\n", l, c, piece->first);
			return (-1);
		}
		//printf("test2 l:%d c:%d\n", l, c);
		if (test_piece_grid(piece, l, c, grid))
		{
			//printf("return pos l:%d c:%d pos:%d\n", l, c, 16 * l + c);
			return (l * 16 + c);
		}
		c--;
		if (c == -1)
		{
			l--;
			c = grid_size - piece->tetra->w;
		}
	}
	return (-1);
}

int		get_next_position(t_piece *piece, unsigned short int grid[],
	unsigned char grid_size)
{
	char	l;
	char	c;

	//printf("\n-- get_next_position %d\n", piece->tetra->n);
	if (piece->l == -1)
	{
		piece->l = piece->first = -1 ? 0 : piece->first / 16;
		piece->c = piece->first = -1 ? 0 : piece->first % 16;
		l = piece->l;
		c = piece->c;
	}
	else
	{
		//printf("!(piece->l | piece->c): %d mod (piece->c + 1 + piece->tetra->w):%d grid_size:%d (piece->c + 1 + piece->tetra->w) mod grid_size):%d\n", !(piece->l | piece->c), piece->c + 1 + piece->tetra->w, grid_size, (piece->c + 1 + piece->tetra->w) % grid_size);
		if (!((piece->c + piece->tetra->w) % grid_size))
		{
			l = piece->l + 1;
			c = 0;
		}
		else
		{
			l = piece->l;
			c = piece->c + 1;
		}
	}
	//printf("et1 l:%d piece->l:%d c:%d piece->c:%d\n", l, piece->l, c, piece->c);
	if (l * 16 + c > piece->last)
	{
		//printf("(exit) l:%d c:%d\n", l, c);
		return (0);
	}
	//printf("et1 l:%d piece->l:%d c:%d piece->c:%d\n", l, piece->l, c, piece->c);
	piece->l = l;
	piece->c = c;
	//printf("et3 l:%d piece->l:%d c:%d piece->c:%d\n", l, piece->l, c, piece->c);
	if (!test_piece_grid(piece, l, c, grid))
	{
		//printf("(recurs) l:%d c:%d\n", piece->l, piece->c);
		return (get_next_position(piece, grid, grid_size));
	}
	//printf("------------\n");
	return (1);
}

int		solver_add_piece_grid(t_piece *pieces, unsigned char *p_bt_size,
	unsigned short int grid[], unsigned char grid_size)
{
	t_piece 			*piece;
	int					next;

	//printf("solver_add_piece_grid %d\n", *p_bt_size);
	piece = pieces + *p_bt_size;
	piece->last = get_last_position(&pieces[*p_bt_size], grid, grid_size);
	//printf("sapg piece->last %d\n", piece->last);
	if (piece->last == -1)
	{
		//printf("(exit) last = %d\n", piece->last);
		return (1);
	}
	next = get_next_position(&pieces[*p_bt_size], grid, grid_size);
	if (!next)
	{
		//printf("sapg next KO l:%d c:%d\n", pieces[*p_bt_size].l, pieces[*p_bt_size].c);
		pieces[*p_bt_size].l = -1;
		pieces[*p_bt_size].c = -1;
		pieces[*p_bt_size].first = -1;
		pieces[*p_bt_size].last = -1;
		if (!(*p_bt_size))
			return (1);
		(*p_bt_size)--;
	}
	else
	{
		//printf("sapg next OK l:%d c:%d\n", pieces[*p_bt_size].l, pieces[*p_bt_size].c);
		place_piece_grid(&pieces[*p_bt_size], grid);
		(*p_bt_size)++;
	}
	return (0);
}

unsigned char	calc_grid_size(int pieces_nb)
{
	unsigned char		i;

	if (!pieces_nb)
		return (-1);
	i = 2;
	while (i * i < 4 * pieces_nb)
		i++;
	return (i);
}

int 	solver_write_grid(unsigned short int grid[], unsigned char grid_size)
{
	unsigned char		i;
	unsigned char		j;

	//printf("---*---*---*---* %d\n", grid_size);
	ft_putstr("---*---*---*---* ");
	ft_putnbr(grid_size);
	ft_putstr(" \n");
	i = 0;
	while (i < grid_size)
	{
		j = 16;
		while (j > 16 - grid_size)
		{
			j--;
			ft_putchar((grid[i] >> j) & 1u ? '#' : '.');
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr("---*---*---*---*\n");
	return (1);
}

int		solver_init(unsigned short int grid[], unsigned char grid_size,
	t_piece *pieces, unsigned char *p_bt_size)
{
	unsigned char		i;
	unsigned char		j;

	//printf("------ solver_init i:\n");
	i = 0;
	while (i < GRID_MAX)
	{
		grid[i] = (unsigned short int)GRID_ALL_ONE;
		if (i < grid_size)
		{
			j = 0;
			while (j < grid_size)
			{
				grid[i] &= ~(1u << (15 - j));
				j++;
			}
		}
		i++;
	}
	i = *p_bt_size;
	while (i--)
	{
		pieces[i - 1].l = -1;
		pieces[i - 1].c = -1;
		pieces[i - 1].first = -1;
		pieces[i - 1].last = -1;
	}
	*p_bt_size = 0;
	return (1);
}

int		solver(t_piece pieces[], int pieces_nb)
{
	unsigned char		grid_size;
	unsigned short int	grid[GRID_MAX];
	unsigned char		bt_size;
	unsigned char		grid_ko;

	grid_size = calc_grid_size(pieces_nb);
	//printf("grid_size : %d\n", grid_size);
	bt_size = 0;
	while (bt_size < pieces_nb)
	{
		grid_ko = 0;
		solver_init(grid, grid_size, pieces, &bt_size);
		//solver_pieces_init(pieces, pieces_nb);
		//printf("INITIAL GRID\n");
		solver_write_grid(grid, grid_size);
		while (!grid_ko && bt_size != pieces_nb)
		{
			grid_ko = solver_add_piece_grid(pieces, &bt_size, grid, grid_size);
			//printf("PROGRESS GRID -> !grid_ko: %d bt_size:%d / pieces_nb:%d ==> %d\n", !grid_ko , bt_size, pieces_nb, bt_size == pieces_nb );
			solver_write_grid(grid, grid_size);
		}
		if (bt_size < pieces_nb)
			grid_size++;
		//bt_size = pieces_nb;
	}
	return (grid_size);
}
