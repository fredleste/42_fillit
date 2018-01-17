/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 09:00:49 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/17 12:02:16 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_test.h"
#include "main.h"
#include "mock.h"
#include "test.h"
#include "solver.h"
#include "output.h"

int		test_put_error(int error)
{
	if (error)
		ft_putstr("error\n");
	else
		ft_putstr(FILLIT_TEST_USAGE);
	return (1);
}

int		main(int argc, char *argv[])
{
	char	file_output_test[256];
	char	description[2048];
	char	files_input_test[FILLIT_TEST_INPUT_NB][256] = {FILLIT_TEST_INPUT_FILE_0, FILLIT_TEST_INPUT_FILE_1};
	clock_t timer_t[FILLIT_TEST_INPUT_NB][5];
	FILE	*fd;
	int		i;
	int		j;
	int		t;
	t_tetra	tetras_lib[TETRAS_LIB_NB];
	t_piece	pieces[PIECES_NB_MAX];
	int		pieces_nb;
	int		grid_size;
	
	/*
	//put_error_log("-------------------------------\n------------------ INIALISATION\n\n");
	if (!test_params_mock(argc))
		return (put_error(0));
	//put_error_log("-------------------------------\n------------------ INIT TETRAS\n\n");
	init_tetras_lib_mock(tetras_lib);
	//put_error_log("-------------------------------\n------------------ TEST SOURCE\n\n");
	pieces_nb = test_source_mock(argv[1], tetras_lib, pieces);
	if (pieces_nb == -1)
		return (put_error(1));
	//printf("nb_pieces : %d\n", pieces_nb);
	//put_error_log("-------------------------------\n------------------ SOLVER\n\n");
	grid_size = solver(pieces, pieces_nb);
	if (grid_size == -1)
		return (put_error(1));
	//put_error_log("-------------------------------\n------------------ PUT GRID\n\n");
	return	(put_grid(pieces, pieces_nb, grid_size));
	*/
	
	if (argc != 1 && argc != 3 && argc != 5)
		return(test_put_error(0));
	ft_strcpy(file_output_test, FILLIT_TEST_OUTPUT_FILE);
	ft_strcpy(description, FILLIT_TEST_DESCRIPTION);
	if (argc == 3 || argc == 5)
	{
		if ((!ft_strcmp(argv[1], "-f") && !ft_strcmp(argv[1], "-d")) || (argc == 5 && !ft_strcmp(argv[1], argv[3])))
			return(test_put_error(0));
		if (!ft_strcmp(argv[1], "-f"))
			ft_strcpy(file_output_test, argv[2]);
		else if (!ft_strcmp(argv[1], "-d"))
			ft_strcpy(description, argv[2]);
		if (argc == 5)
		{
			if (!ft_strcmp(argv[3], "-f"))
				ft_strcpy(file_output_test, argv[4]);
			else if (!ft_strcmp(argv[3], "-d"))
				ft_strcpy(description, argv[4]);
		}
	}
	/**
	* ------------------------------------------------------ FILLIT (WITH TIMER)
	**/
	init_tetras_lib_mock(tetras_lib);
	t = FILLIT_TEST_INPUT_NB;
	while (t--)
	{
		timer_t[t][0] = clock();
		pieces_nb = test_source_mock(files_input_test[t], tetras_lib, pieces);
		if (pieces_nb == -1)
			return (put_error(1));
		timer_t[t][1] = clock();
		grid_size = solver(pieces, pieces_nb);
		if (grid_size == -1)
			return (put_error(1));
		timer_t[t][2] = clock();
		if (put_grid(pieces, pieces_nb, grid_size))
			return (1);
		timer_t[t][3] = clock();
		timer_t[t][4] = (clock_t)0;
		i = 3;
		while (i)
		{
			timer_t[t][i] -= timer_t[t][i - 1];
			timer_t[t][4] += timer_t[t][i];
			i--;
		}
	}
	/**
	* ----------------------------------------------------------- OUTPUT IN FILE
	**/
	if (!(fd = fopen(file_output_test, "a")))
		return(test_put_error(0));
	fprintf(fd, "\n\n%s\n", description);
	fprintf(fd, "|%40s|%20s|%20s|%20s|%20s|%20s|\n", "File", "Result", "Test duration", "Solver duration", "Output duration", "Total duration");
	// Line
	i = 0;
	while (i < 6)
	{
		fprintf(fd, "|");
		j = !i ? 40 : 20;
		while (j--)
			fprintf(fd, "-");
		i++;
	}
	fprintf(fd, "|\n");
	// Line end
	t = FILLIT_TEST_INPUT_NB;
	while (t--)
	{
		fprintf(fd, "|%40s|%20d|%20.4f|%20.4f|%20.4f|%20.4f|\n", files_input_test[t], grid_size, (double)timer_t[t][1] / CLOCKS_PER_SEC, (double)timer_t[t][2] / CLOCKS_PER_SEC, (double)timer_t[t][3] / CLOCKS_PER_SEC, (double)timer_t[t][4] / CLOCKS_PER_SEC);
		// Line
		i = 0;
		while (i < 6)
		{
			fprintf(fd, "|");
			j = !i ? 40 : 20;
			while (j--)
				fprintf(fd, "-");
			i++;
		}
		fprintf(fd, "|\n");
		// Line end
	}
	if (fclose(fd))
		return(test_put_error(0));
	return(0);
}
