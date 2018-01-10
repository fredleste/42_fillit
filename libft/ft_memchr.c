/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:51:39 by mbaron            #+#    #+#             */
/*   Updated: 2017/12/19 14:18:01 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;

	p_s = (unsigned char *)s;
	while (n--)
	{
		if (*p_s == (unsigned char)c)
			return ((void *)p_s);
		if (n)
			p_s++;
	}
	return (NULL);
}
