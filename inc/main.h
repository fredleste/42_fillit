/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:03:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/10 20:42:45 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdlib.h>
# include "libft.h"
# include "tetras_lib.h"
# define GRID_MAX 16
# define TETRAS_LIB_NB 19
# define FILLIT_USAGE "usage: ./fillit source_file\n"

typedef struct	s_bt
{
	struct s_bt		*next;
	void			*content;
	unsigned int	content_size;
}				t_bt;
void 	init_tetras_lib	(t_tetra tetras_lib[]);
int 	test_params(int argc);
int 	test_source(char *file_name, t_tetra tetras_lib[], t_tetra **tetras);
int		solver(t_tetra **tetras, int tetras_nb, t_bt **bt);
int		put_error(int error);
int		put_error_log(const char *str);
void	put_grid(t_bt **bt, int grid_size);
#endif
