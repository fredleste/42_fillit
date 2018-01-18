/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:51:32 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/18 19:07:00 by mbaron           ###   ########.fr       */
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

void	solver_init_piece(t_piece *piece)
{
	piece->l = -1;
	piece->c = -1;
	piece->first = -1;
	piece->last = -1;
}

int		test_piece_grid(t_piece *piece, int l, int c, int grid[])
{
	int		i;
	
	printf("-- test_piece_grid n:%d h:%d w:%d l:%d c:%d\n", piece->n, piece->h, piece->w, l, c);
	i = piece->max;
	while (i > piece->min)
	{
		if (piece->n & (1 << i) && !(grid[l] & (1 << (i - c))))
		{
			printf("indice:%d l:%d i + c:%d\n", i, l, i - c);
			//printf("i:%d ok:%d ko: %d l+im4:%d dec:%d\n", i, ok, ko, l + i / 4, 15 - c - i % 4);
		}
		if (piece->n & (1 << i) && (grid[l] & (1 << (i - c))))
		{
			return (0);
			//printf("i:%d ok:%d ko: %d l+im4:%d dec:%d\n", i, ok, ko, l + i / 4, 15 - c - i % 4);
		}
		if (!(i % 4))
		{
			l++;
			c -= 4;
		}
		i--;
	}
	//piece->first = 16 * l + c;
	//p->pos = 16 * l + c;
	return (1);
}

int		toggle_piece_grid(t_piece *piece, int grid[], int place)
{
	int		i;
	int		l;
	int		c;
	//printf("-- place_piece_grid n:%d l:%d c:%d\n", piece->tetra->n, piece->l, piece->c);
	i = piece->max;
	l = piece->l;
	c = piece->c;
	while (i > piece->min)
	{
		//printf("i:%d max:%d\n", i, max);
		if (piece->n & (1 << i))
		{
			printf("indice:%d l:%d i + c:%d\n", i, l, i - c);
			if (place)
				grid[l] |= 1 << (i - c);
			else
				grid[l] &= ~(1 << (i - c));
		}
		if (!(i % 4))
		{
			l++;
			c -= 4;
		}
		i--;
	}
	return (1);
}

int		get_last_position(t_piece *piece, int grid[], int grid_size)
{
	int		l;
	int		c;

	//printf("\n-- get_last_position %d\n", piece->tetra->n);
	l = grid_size - piece->h;
	c = grid_size - piece->w;
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
			c = grid_size - piece->w;
		}
	}
	return (-1);
}

int		get_next_position(t_piece *pieces, int bt_size, int grid[], int grid_size)
{
	// int		l;
	// int		c;
	t_piece	*p;

	p = &pieces[bt_size];
	printf("\n-- get_next_position %d (p->l): %d (p->c):%d\n", p->n, p->l, p->c);
	if (p->l * 16 + p->c == p->last)
	{
		return (0);
	}
	if (p->l == -1 && p->prev == -1)
	{
		p->l = pieces[p->prev].l;
		p->c = pieces[p->prev].c;
		//printf("first test : l: %d c:%d", l, c);
	}
	//printf("!(piece->l | piece->c): %d mod (piece->c + 1 + piece->tetra->w):%d grid_size:%d (piece->c + 1 + piece->tetra->w) mod grid_size):%d\n", !(piece->l | piece->c), piece->c + 1 + piece->tetra->w, grid_size, (piece->c + 1 + piece->tetra->w) % grid_size);
	
	if (p->l == -1)
	{
		p->l = 0;
		p->c = 0;
	}
	else if (!((p->c + p->w) % grid_size))
	{
		p->l += 1;
		p->c = 0;
	}
	else
		p->c += 1;
	printf("et3 piece->l:%d c:piece->c:%d\n", p->l, p->c);
	if (!test_piece_grid(p, p->l, p->c, grid))
	{
		//printf("(recurs) l:%d c:%d\n", piece->l, piece->c);
		return (get_next_position(pieces, bt_size, grid, grid_size));
	}
	//printf("------------\n");
	return (1);
}

int		solver_add_piece_grid(t_piece *pieces, int *p_bt_size, int grid[],
	int grid_size)
{
	t_piece	*piece;
	int		next;

	printf("\n-- solver_add_piece_grid %d\n", *p_bt_size);
	piece = pieces + *p_bt_size;
	piece->last = get_last_position(&pieces[*p_bt_size], grid, grid_size);
	printf("sapg piece->last %d\n", piece->last);
	if (piece->last == -1)
	{
		printf("(exit) last = %d\n", piece->last);
		solver_init_piece(&pieces[*p_bt_size]);
		if (!(*p_bt_size))
			return (1);
		(*p_bt_size)--;
		toggle_piece_grid(&pieces[*p_bt_size], grid, 0);
	}
	next = get_next_position(pieces, *p_bt_size, grid, grid_size);
	if (!next)
	{
		printf("sapg next KO l:%d c:%d\n", pieces[*p_bt_size].l, pieces[*p_bt_size].c);
		solver_init_piece(&pieces[*p_bt_size]);
		if (!(*p_bt_size))
			return (1);
		(*p_bt_size)--;
		toggle_piece_grid(&pieces[*p_bt_size], grid, 0);
	}
	else
	{
		printf("sapg next OK l:%d c:%d\n", pieces[*p_bt_size].l, pieces[*p_bt_size].c);
		toggle_piece_grid(&pieces[*p_bt_size], grid, 1);
		piece->first = 16 * piece->l + piece->c;
		(*p_bt_size)++;
	}
	return (0);
}

int		calc_grid_size(int pieces_nb)
{
	int		i;
	
	printf("calc_grid_size pieces_nb:%d\n", pieces_nb);
	if (!pieces_nb)
		return (-1);
	i = 2;
	while (i * i < 4 * pieces_nb)
		i++;
	printf("calc_grid_size pieces_nb:%d\n", pieces_nb);
	return (i);
}

int		solver_write_grid(int grid[], int grid_size)
{
	int		i;
	int		j;

	//printf("---*---*---*---* %d\n", grid_size);
	ft_putstr("---*---*---*---* ");
	ft_putnbr(grid_size);
	ft_putstr(" \n");
	i = 0;
	while (i < grid_size)
	{
	   ft_putnbr(grid[i]);
	   ft_putstr(" ");
	   i++;
	}
	ft_putchar('\n');
	i = 0;
	while (i < 16)
	{
		j = 16;
		while (j > 0)
		{
			j--;
			ft_putchar((grid[i] >> j) & 1 ? '#' : '.');
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr("---*---*---*---*\n");
	return (1);
}

int		solver_init(int grid[], int grid_size, t_piece *pieces, int *p_bt_size)
{
	int		i;
	int		j;

	//printf("------ solver_init i:\n");
	i = 0;
	while (i < GRID_MAX)
	{
		grid[i] = GRID_ALL_ONE;
		if (i < grid_size)
		{
			j = 0;
			while (j < grid_size)
			{
				grid[i] &= ~(1 << (15 - j));
				j++;
			}
		}
		i++;
	}
	i = *p_bt_size + 1;
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
	int		grid_size;
	int		grid[GRID_MAX];
	int		bt_size;
	int		grid_ko;

	grid_size = calc_grid_size(pieces_nb);
	//printf("grid_size : %d\n", grid_size);
	bt_size = 0;
	while (bt_size < pieces_nb)
	{
		grid_ko = 0;
		solver_init(grid, grid_size, pieces, &bt_size);
		//solver_pieces_init(pieces, pieces_nb);
		printf("\n\nINITIAL GRID ====================== %d\n", grid_size);
		solver_write_grid(grid, grid_size);
		while (!grid_ko && bt_size != pieces_nb)
		{
			grid_ko = solver_add_piece_grid(pieces, &bt_size, grid, grid_size);
			//printf("PROGRESS GRID -> !grid_ko: %d bt_size:%d / pieces_nb:%d ==> %d\n", !grid_ko , bt_size, pieces_nb, bt_size == pieces_nb );
			solver_write_grid(grid, grid_size);
		}
		if (bt_size < pieces_nb)
			grid_size++;
	}
	return (grid_size);
}
