/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:44:23 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/20 19:45:40 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_TEST_H
# define MAIN_TEST_H
# include <stdio.h>
# include <time.h>
# define FILLIT_TEST_USAGE "./fillit_test [-f output_file_name][-d description]\n"
# define FILLIT_TEST_OUTPUT_FILE "./output/result.fillit"
# define FILLIT_TEST_DESCRIPTION "Default description"
# define FILLIT_TEST_INPUT_FILE_0 "./samples/valid_sample2.fillit"
# define FILLIT_TEST_INPUT_FILE_1 "./samples/valid_sample_forum_5.fillit"
# define FILLIT_TEST_INPUT_FILE_2 "./samples/valid_sample_forum_10.fillit"
# define FILLIT_TEST_INPUT_FILE_3 "./samples/valid_sample_forum_5.fillit"
# define FILLIT_TEST_INPUT_FILE_4 "./samples/valid_sample_forum_10.fillit"
# define FILLIT_TEST_INPUT_FILE_5 "./samples/valid_sample_forum_11.fillit"
# define FILLIT_TEST_INPUT_FILE_6 "./samples/valid_sample_forum_12.fillit"
# define FILLIT_TEST_INPUT_FILE_7 "./samples/valid_sample_forum_13.fillit"
# define FILLIT_TEST_INPUT_FILE_8 "./samples/valid_sample_forum_14.fillit"
# define FILLIT_TEST_INPUT_FILE_9 "./samples/valid_sample_forum_15.fillit"
# define FILLIT_TEST_INPUT_NB 3

int		test_put_error(int error);
int		test_output(char test_params[2][2048],
	const char files_input_test[FILLIT_TEST_INPUT_NB][256],
	int grid_size[FILLIT_TEST_INPUT_NB],
	clock_t timer_t[FILLIT_TEST_INPUT_NB][4]);
void	init_tetras_lib(int tetras_lib[]);
#endif
