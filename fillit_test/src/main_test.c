/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 09:00:49 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/24 14:45:36 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_test.h"
#include "fillit.h"

static int		test_test_params(int argc, char *argv[],
	char test_params[2][2048])
{
	if (argc != 1 && argc != 3 && argc != 5)
		return (test_put_error(0));
	ft_strcpy(test_params[0], FILLIT_TEST_OUTPUT_FILE);
	ft_strcpy(test_params[1], FILLIT_TEST_DESCRIPTION);
	if (argc == 3 || argc == 5)
	{
		if ((ft_strcmp(argv[1], "-f") && ft_strcmp(argv[1], "-d"))
			|| (argc == 5
				&& ((ft_strcmp(argv[3], "-f") && ft_strcmp(argv[3], "-d"))
					|| !ft_strcmp(argv[1], argv[3]))))
			return (test_put_error(0));
		if (!ft_strcmp(argv[1], "-f"))
			ft_strcpy(test_params[0], argv[2]);
		else if (!ft_strcmp(argv[1], "-d"))
			ft_strcpy(test_params[1], argv[2]);
		if (argc == 5)
		{
			if (!ft_strcmp(argv[3], "-f"))
				ft_strcpy(test_params[0], argv[4]);
			else if (!ft_strcmp(argv[3], "-d"))
				ft_strcpy(test_params[1], argv[4]);
		}
	}
	return (0);
}

static int		main_fillit(const char files_input_test[256],
	clock_t timer_t[4])
{
	int		tetras_lib[TETRAS_LIB_NB];
	t_piece	pieces[PIECES_NB_MAX];
	int		pieces_nb;
	int		grid_size;
	int		i;

	init_tetras_lib(tetras_lib);
	timer_t[0] = clock();
	pieces_nb = test_source((char *)files_input_test, tetras_lib, pieces);
	if (pieces_nb == -1)
		return (!put_error(1));
	printf("------------- %s\n", files_input_test);
	timer_t[1] = clock();
	grid_size = solver(pieces, pieces_nb);
	if (grid_size == -1)
		return (!put_error(1));
	timer_t[2] = clock();
	printf("------------> %20.4f\n", ((double)timer_t[2] - (double)timer_t[1]) / CLOCKS_PER_SEC);
	if (put_grid(pieces, pieces_nb, grid_size))
		return (0);
	timer_t[3] = clock();
	i = 4;
	while (--i)
		timer_t[i] -= timer_t[i - 1];
	return (grid_size);
}

int				main(int argc, char *argv[])
{
	char		test_params[2][2048];
	/*
	const char	files_input_test[FILLIT_TEST_INPUT_NB][256] =
	{FILLIT_TEST_INPUT_FILE_0, FILLIT_TEST_INPUT_FILE_1,
	FILLIT_TEST_INPUT_FILE_2, FILLIT_TEST_INPUT_FILE_3,
	FILLIT_TEST_INPUT_FILE_4, FILLIT_TEST_INPUT_FILE_5,
	FILLIT_TEST_INPUT_FILE_6, FILLIT_TEST_INPUT_FILE_7,
	FILLIT_TEST_INPUT_FILE_8, FILLIT_TEST_INPUT_FILE_9};
	*/
	const char	files_input_test[FILLIT_TEST_INPUT_NB][256] =
	{FILLIT_TEST_INPUT_FILE_3, FILLIT_TEST_INPUT_FILE_2,
	FILLIT_TEST_INPUT_FILE_1, FILLIT_TEST_INPUT_FILE_0};
	clock_t		timer_t[FILLIT_TEST_INPUT_NB][4];
	int			grid_size[FILLIT_TEST_INPUT_NB];
	int			t;

	if (test_test_params(argc, argv, test_params))
		return (1);
	t = FILLIT_TEST_INPUT_NB;
	while (--t > -1)
	{
		grid_size[t] = main_fillit(
			files_input_test[t],
			timer_t[t]);
		//t--;
	}
	return (test_output(test_params, files_input_test, grid_size, timer_t));
}
