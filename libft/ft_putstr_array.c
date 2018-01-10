/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:13:16 by mbaron            #+#    #+#             */
/*   Updated: 2017/12/18 16:55:51 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <strings.h>
#include "libft.h"

void	ft_putstr_array(char *tab[], size_t tabl)
{
	size_t	i;

	i = 0;
	while (i < tabl)
	{
		ft_putstr(tab[i]);
		write(1, "\n", 1);
		i++;
	}
}
