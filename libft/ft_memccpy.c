/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:48:34 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/20 14:34:06 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		x;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*d++ = *s++) == x)
			return (d);
		i++;
	}
	return (NULL);
}
