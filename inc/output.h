/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleste-l <fleste-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:59:06 by fleste-l          #+#    #+#             */
/*   Updated: 2018/01/16 15:31:28 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H
# define FILLIT_USAGE "usage: ./fillit source_file\n"

int		put_error(int error);
int		put_error_log(const char *str);
int		put_grid(t_piece *pieces, int pieces_nb, int grid_size);
#endif
