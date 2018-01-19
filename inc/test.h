/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleste-l <fleste-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:50:14 by fleste-l          #+#    #+#             */
/*   Updated: 2018/01/19 15:22:17 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUF_SIZE 545

void	init_pieces(t_piece pieces[], int pieces_nb);
int		test_source(char *file_name, int tetras_lib[], t_piece pieces[]);
#endif
