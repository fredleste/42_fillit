/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 20:13:20 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/26 13:13:42 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		toggle_piece_grid(t_piece *piece, int grid[])
{
	int		i;

	i = 0;
	while (i < piece->h)
	{
		grid[piece->l + i] ^= ((piece->n << (4 * i)) & 0xF000) >> piece->c;
		i++;
	}
}

static int		test_piece_grid(t_piece *piece, int l, int c, int grid[])
{
	int		i;

	i = 0;
	while (i < piece->h)
	{
		if (((grid[l + i] << c) & 0xF000) & ((piece->n << (4 * i)) & 0xF000))
			return (0);
		i++;
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

	p = &pieces[bt_size];
	l_min = p->prev != -1 ? pieces[p->prev].l : 0;
	c_min = p->prev != -1 ? pieces[p->prev].c : 0;
	l = grid_size - p->h;
	c = grid_size - p->w;
	while (l > l_min || (l == l_min && c >= c_min))
	{
		if (p->pos > 16 * l + c)
			return (-1);
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

	p = &pieces[bt_size];
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

int				solver_add_piece_grid(t_piece *pieces, int *p_bt_size,
	int grid[], int grid_size)
{
	t_piece	*piece;

	piece = pieces + *p_bt_size;
	if (piece->pos == -1)
		piece->last = get_last_position(pieces, *p_bt_size, grid, grid_size);
	if ((piece->last == -1 || (piece->last != -1 && piece->pos == piece->last))
		? 0 : get_next_position(pieces, *p_bt_size, grid, grid_size))
	{
		toggle_piece_grid(piece, grid);
		(*p_bt_size)++;
		pieces[*p_bt_size].last = -1;
	}
	else if (piece->pos >= piece->last)
	{
		init_piece(&pieces[*p_bt_size]);
		if (!(*p_bt_size))
			return (0);
		(*p_bt_size)--;
		toggle_piece_grid(&pieces[*p_bt_size], grid);
	}
	return (1);
}
