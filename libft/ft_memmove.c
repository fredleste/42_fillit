/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:53:12 by mbaron            #+#    #+#             */
/*   Updated: 2017/12/01 09:37:01 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d < s)
		while (i < len)
		{
			*d++ = *s++;
			i++;
		}
	else
	{
		d += len;
		s += len;
		while (i < len)
		{
			*--d = *--s;
			i++;
		}
	}
	return (dst);
}
