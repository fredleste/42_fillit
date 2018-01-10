/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:03:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/10 17:14:00 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include "tetras_lib.h"
# include "test.h"
# include "solver.h"
# include "output.h"
# define GRID_MAX 16
# define TETRAS_LIB_NB 19

typedef struct	s_bt
{
	struct s_bt		*next;
	void			*content;
	unsigned int	content_size;
}				t_bt;
#endif
