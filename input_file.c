/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleste-l <fleste-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:59:05 by fleste-l          #+#    #+#             */
/*   Updated: 2018/01/22 19:00:29 by fleste-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	read_file(char *file_name, char buf[])
{
	int		n;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	n = read(fd, buf, BUF_SIZE);
	if (close(fd) == -1)
		return (0);
	return (n);
}

int			put_file(char *file_name, char *str_pieces)
{
	int		n;
	int		i;
	int		j;
	char	buf[BUF_SIZE + 1];

	n = read_file(file_name, buf);
	if ((n + 1) % 21 != 0)
		return (-1);
	i = 0;
	j = 0;
	while (i < n)
	{
		if ((i + 1 - i / 21) % 5 == 0 || (i + 1) % 21 == 0)
		{
			if (buf[i] != '\n')
				return (-1);
		}
		else if (buf[i] != '.' && buf[i] != '#')
			return (-1);
		else
			str_pieces[j++] = buf[i];
		i++;
	}
	str_pieces[j] = '\0';
	return ((n + 1) / 21);
}
