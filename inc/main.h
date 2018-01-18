/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:03:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/18 14:01:13 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "tetras_lib.h"
# define GRID_MAX 16
# define TETRAS_LIB_NB 19
# define PIECES_NB_MAX 26

typedef struct	s_piece
{
	int			n;
	int			min;
	int			max;
	int			h;
	int			w;
	int			l;
	int			c;
	int			first;
	int			last;
	int			pos;
	int			prev;
}				t_piece;
#endif
