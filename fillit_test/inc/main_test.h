/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 11:44:23 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/17 11:49:30 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_TEST_H
# include <stdio.h>
# include <time.h>
# define MAIN_TEST_H
# define FILLIT_TEST_USAGE "./fillit_test [-f output_file_name][-d description]"
# define FILLIT_TEST_OUTPUT_FILE "./output/result.fillit"
# define FILLIT_TEST_DESCRIPTION "Default description"
# define FILLIT_TEST_INPUT_FILE_0 "../samples/valid_sample.fillit"
# define FILLIT_TEST_INPUT_FILE_1 "../samples/invalid_sample.fillit"
# define FILLIT_TEST_INPUT_NB 2

int		test_put_error(int error);
#endif
