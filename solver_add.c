/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:13:20 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/23 18:39:59 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		toggle_piece_grid(t_piece *piece, int grid[])
{
	int		i;
	int		l;
	int		c;

	i = piece->max;
	l = piece->l;
	c = piece->c;
	while (i > piece->min)
	{
		if (piece->n & (1 << i))
			grid[l] ^= 1 << (i - c);
		if (!(i % 4))
		{
			l++;
			c -= 4;
		}
		i--;
	}
	return (1);
}

static int		get_next_line_last(t_piece *piece, int grid[], int l)
{
	int		i;

	i = 0;
	while (i < piece->h)
	{
		if (grid[l + i] == GRID_ALL_ONE)
			return (l - piece->h + i);
		i++;
	}
	return (l);
}

static int		get_next_line_next(t_piece *piece, int grid[], int l)
{
	int		i;

	i = l + piece->h;
	while (i > l)
	{
		i--;
		//printf("get_next_line next:%d ltest:%d lnouv:%d\n", next, l + i - 1, l + i);
		if (grid[i] == GRID_ALL_ONE)
			return (i + 1);
	}
	return (l);
}

static int		test_piece_grid(t_piece *piece, int l, int c, int grid[])
{
	int		i;

	i = piece->max;
	while (i > piece->min)
	{
		if ((piece->n & (1 << i)) && (grid[l] & (1 << (i - c))))
			return (0);
		if (!(i % 4))
		{
			l++;
			c -= 4;
		}
		i--;
	}
	return (1);
}

static int		get_last_position(t_piece *pieces, int bt_size, int grid[],
	int grid_size)
{
	t_piece	*p;
	int		l;
	int		c;
	int		l_min;
	int		c_min;
	int		l_next;

	p = &pieces[bt_size];
	l_min = p->prev != -1 ? pieces[p->prev].l : 0;
	c_min = p->prev != -1 ? pieces[p->prev].c : 0;
	l = grid_size - p->h;
	c = grid_size - p->w;
	while (l > l_min || (l == l_min && c >= c_min))
	{
		if (p->pos > 16 * l + c)
			return (-1);
		l_next = get_next_line_last(p, grid, l);
		if (l != l_next)
		{
			//printf("get_last_position gs:%d p:%d l:%d l_next:%d l_min:%d\n", grid_size, bt_size, l, l_next, l_min);
			if (l_next >= l_min)
			{
				l = l_next;
				c = grid_size - p->w;
			}
			else
				return(0);
		}
		if (test_piece_grid(p, l, c, grid))
			return (l * 16 + c);
		c--;
		if (c == -1)
		{
			l--;
			c = grid_size - p->w;
		}
	}
	return (-1);
}

static int		get_next_position(t_piece *pieces, int bt_size, int grid[],
	int grid_size)
{
	t_piece	*p;
	int		l_next;

	p = &pieces[bt_size];
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
	l_next = get_next_line_next(p, grid, p->l);
	if (p->l != l_next)
	{
		//printf("get_next_position gs:%d p:%d last:%d l:%d l_next:%d gs-p->h:%d\n", grid_size, bt_size, p->last, p->l, l_next, grid_size - p->h);

		if (l_next <= grid_size - p->h)
		{
			//printf("continue\n");
			p->l = l_next;
			p->c = 0;
		}
		else
		{
			//printf("exit\n");
			p->pos = p->last;
			return(0);
		}
	}
	p->pos = 16 * p->l + p->c;
	return (test_piece_grid(p, p->l, p->c, grid));
}

int				solver_add_piece_grid(t_piece *pieces, int *p_bt_size,
	int grid[],
	int grid_size)
{
	t_piece	*piece;
	int		next;

	piece = pieces + *p_bt_size;
	if (piece->pos == -1)
	{
		if (piece->prev != -1)
			piece->pos = pieces[*p_bt_size].pos;
		piece->last = get_last_position(pieces, *p_bt_size, grid, grid_size);
		
	}
	next = (piece->last == -1 || (piece->last > -1
		&& piece->pos == piece->last))
		? 0 : get_next_position(pieces, *p_bt_size, grid, grid_size);
	if (next)
	{
		toggle_piece_grid(piece, grid);
		//printf("add %d n:%d l:%d c:%d pos:%d last:%d\n", *p_bt_size, piece->n, piece->l, piece->c, piece->pos, piece->last);
		//solver_write_grid(grid, grid_size);
		piece->pos = 16 * piece->l + piece->c;
		(*p_bt_size)++;
		pieces[*p_bt_size].last = -1;
	}
	else if (piece->pos >= piece->last)
	{
		//printf("remove %d n:%d l:%d c:%d pos:%d last:%d\n", *p_bt_size, piece->n, piece->l, piece->c, piece->pos, piece->last);
		init_piece(&pieces[*p_bt_size]);
		if (!(*p_bt_size))
			return (0);
		(*p_bt_size)--;
		toggle_piece_grid(&pieces[*p_bt_size], grid);
		//solver_write_grid(grid, grid_size);
	}
	return (1);
}
