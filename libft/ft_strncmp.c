/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:30:09 by mbaron            #+#    #+#             */
/*   Updated: 2017/12/21 14:34:57 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i]
			&& i < n)
		i++;
	return (i == n ? 0 : (unsigned char)s1[i] - (unsigned char)s2[i]);
}
