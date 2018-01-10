/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:47:52 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/10 17:30:19 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include "main.h"

typedef struct	s_bt
{
	struct s_bt		*next;
	void			*content;
	unsigned int	content_size;
}				t_bt;
int	solver(t_tetra **tetras, int tetras_nb, t_bt **bt);
#endif
