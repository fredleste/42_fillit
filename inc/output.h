/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:29:38 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/10 17:28:35 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H
# include "main.h"
# define FILLIT_USAGE "usage: fillit source_file\n"

int		put_error(int error);
void	put_grid(t_bt **bt, int grid_size);
#endif
