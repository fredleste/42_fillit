/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:51:32 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/19 18:25:21 by mbaron           ###   ########.fr       */
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
	piece->pos = -1;
}

int		test_piece_grid(t_piece *piece, int l, int c, int grid[])
{
	int		i;
	
	//printf("-- test_piece_grid n:%d h:%d w:%d l:%d c:%d\n", piece->n, piece->h, piece->w, l, c);
	i = 0;
	while (i < piece->h)
	{
		if (grid[l + i] == GRID_ALL_ONE)
			return (0);
		i++;
	}
	//printf("test lignes OK: l:%d-%d\n", l, l + i - 1);
	i = piece->max;
	while (i > piece->min)
	{
		//printf("test: i:%d l:%d c:%d (i - c):%d m1:%d m2:%d\n", i, l, c, i - c, piece->n & (1 << i), grid[l] & (1 << (i - c)));
		if ((piece->n & (1 << i)) && (grid[l] & (1 << (i - c))))
		{
			//printf("test piece KO\n");
			return (0);
		}
		if (!(i % 4))
		{
			l++;
			c -= 4;
		}
		i--;
	}
	//printf("test piece OK\n");
	return (1);
}

int		toggle_piece_grid(t_piece *piece, int grid[])
{
	int		i;
	int		l;
	int		c;
	
	//printf("-- toggle_piece_grid n:%d l:%d c:%d\n", piece->n, piece->l, piece->c);
	i = piece->max;
	l = piece->l;
	c = piece->c;
	while (i > piece->min)
	{
		if (piece->n & (1 << i))
		{
			//printf("toogle:%d l:%d i + c:%d\n", i, l, i - c);
			grid[l] ^= 1 << (i - c);
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

int		get_last_position(t_piece *pieces, int bt_size,  int grid[], int grid_size)
{
	t_piece	*p;
	int		l;
	int		c;
	int		l_min;
	int		c_min;

	p = &pieces[bt_size];
	if (p->prev != -1)
	{
		l_min = pieces[p->prev].l;
		c_min = pieces[p->prev].c;
	}
	else
	{
		l_min = -1;
		c_min = -1;
	}
	l = grid_size - p->h;
	c = grid_size - p->w;
	//printf("\n-- get_last_position %d l_min:%d c_min:%d l:%d c:%d \n", p->n, l_min, c_min, l, c);
	while (l > l_min || (l == l_min && c > c_min))
	{
		if (p->pos > 16 * l + c)
		{
			//printf("return -1 l:%d c:%d\n", l, c);
			return (-1);
		}
		if (test_piece_grid(p, l, c, grid))
		{
			//printf("return pos:%d l:%d c:%d\n", 16 * l + c, l, c);
			return (l * 16 + c);
		}
		c--;
		if (c == -1)
		{
			l--;
			c = grid_size - p->w;
		}
	}
	return (-1);
}

int		get_next_position(t_piece *pieces, int bt_size, int grid[], int grid_size)
{
	t_piece	*p;

	p = &pieces[bt_size];
	//printf("\n-- get_next_position %d ini: (p->l): %d (p->c):%d\n", p->n, p->l, p->c);
	if (p->l * 16 + p->c == p->last)
		return (-1);
	if (p->l == -1 && p->prev != -1)
	{
		p->l = pieces[p->prev].l;
		p->c = pieces[p->prev].c;
	}
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
	p->pos = 16 * p->l + p->c;
	return (test_piece_grid(p, p->l, p->c, grid));
}

int		solver_add_piece_grid(t_piece *pieces, int *p_bt_size, int grid[],
	int grid_size)
{
	t_piece	*piece;
	int		next;

	piece = pieces + *p_bt_size;
	//next = 0;
	if (piece->prev != -1)
		piece->pos = pieces[*p_bt_size].pos;
	piece->last = get_last_position(pieces, *p_bt_size, grid, grid_size);
	// while (next != -1)
	// {
		//printf("\n-- solver_add_piece_grid %d -> %d pos:%d, last:%d\n", *p_bt_size, piece->n, piece->pos, piece->last);
		next = (piece->last == -1 || (piece->last > -1
			&& piece->pos == piece->last))
			? 0 : get_next_position(pieces,	*p_bt_size, grid, grid_size);
		if (next)
		{
			//printf("sapg next OK l:%d c:%d\n", piece->l, piece->c);
			toggle_piece_grid(piece, grid);
			piece->pos = 16 * piece->l + piece->c;
			(*p_bt_size)++;
			//next = -1;
		}
		else
		{
			if (piece->pos == piece->last) {
				//printf("sapg next KO l:%d c:%d\n", piece->l, piece->c);
				solver_init_piece(&pieces[*p_bt_size]);
				if (!(*p_bt_size))
					return (0);
				(*p_bt_size)--;
				toggle_piece_grid(&pieces[*p_bt_size], grid);
			}
			//next = -1;
		}
		// next = -1;
	//}
	return (1);
}

int		calc_grid_size(int pieces_nb)
{
	int		i;
	
	//printf("calc_grid_size pieces_nb:%d\n", pieces_nb);
	if (!pieces_nb)
		return (-1);
	i = 2;
	while (i * i < 4 * pieces_nb)
		i++;
	//printf("calc_grid_size pieces_nb:%d\n", pieces_nb);
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
	while (i < grid_size)
	{
		j = 16;
		while (j > 16 - grid_size)
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
	i = *p_bt_size;
	while (i--)
		solver_init_piece(&pieces[i]);
	*p_bt_size = 0;
	return (1);
}

int		solver(t_piece pieces[], int pieces_nb)
{
	int		grid_size;
	int		grid[GRID_MAX];
	int		bt_size;
	int		grid_ok;

	grid_size = calc_grid_size(pieces_nb);
	//printf("grid_size : %d\n", grid_size);
	bt_size = 0;
	while (bt_size < pieces_nb)
	{
		grid_ok = 1;
		solver_init(grid, grid_size, pieces, &bt_size);
		//solver_pieces_init(pieces, pieces_nb);
		//printf("\n\nINITIAL GRID ====================== %d\n", grid_size);
		//solver_write_grid(grid, grid_size);
		while (grid_ok && bt_size != pieces_nb)
		{
			grid_ok = solver_add_piece_grid(pieces, &bt_size, grid, grid_size);
			//printf("\nPROGRESS GRID ================ grid_ok: %d bt_size:%d / pieces_nb:%d ==> %d\n", grid_ok , bt_size, pieces_nb, bt_size == pieces_nb);
			//solver_write_grid(grid, grid_size);
		}
		//solver_write_grid(grid, grid_size);
		if (bt_size < pieces_nb)
			grid_size++;
		// if (grid_size == 5)
		// 	exit(0);
	}
	return (grid_size);
}
