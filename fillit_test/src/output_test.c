/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 08:51:56 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/18 10:37:26 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main_test.h"

int			test_put_error(int error)
{
	if (error)
		ft_putstr("error\n");
	else
		ft_putstr(FILLIT_TEST_USAGE);
	return (1);
}

static void	put_line(FILE *fd)
{
	int		i;
	int		j;

	i = 6;
	while (--i)
	{
		fprintf(fd, "|");
		j = !i ? 40 : 20;
		while (j--)
			fprintf(fd, "-");
	}
	fprintf(fd, "|\n");
}

int			test_output(char test_params[2][2048],
	const char files_input_test[FILLIT_TEST_INPUT_NB][256],
	int grid_size[FILLIT_TEST_INPUT_NB],
	clock_t timer_t[FILLIT_TEST_INPUT_NB][4])
{
	FILE	*fd;
	int		t;

	if (!(fd = fopen(test_params[0], "a")))
		return (test_put_error(0));
	fprintf(fd, "\n\n%s\n", test_params[1]);
	fprintf(fd, "|%40s|%20s|%20s|%20s|%20s|%20s|\n", "File", "Result",
	"Test duration", "Solver duration", "Output duration", "Total duration");
	put_line(fd);
	t = 0;
	while (t < FILLIT_TEST_INPUT_NB)
	{
		fprintf(fd, "|%40s|%20d|%20.4f|%20.4f|%20.4f|%20.4f|\n",
		files_input_test[t], grid_size[t],
		(double)timer_t[t][1] / CLOCKS_PER_SEC,
		(double)timer_t[t][2] / CLOCKS_PER_SEC,
		(double)timer_t[t][3] / CLOCKS_PER_SEC,
		(double)timer_t[t][1] / CLOCKS_PER_SEC
		+ (double)timer_t[t][2] / CLOCKS_PER_SEC
		+ (double)timer_t[t][3] / CLOCKS_PER_SEC);
		put_line(fd);
		t++;
	}
	if (fclose(fd))
		return (test_put_error(0));
	return (0);
}
