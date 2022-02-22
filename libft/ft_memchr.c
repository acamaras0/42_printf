/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:34:01 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/10 13:02:22 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	unsigned char	cc;
	size_t			i;

	i = 0;
	ss = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (*ss == cc)
		{
			return (ss);
		}
		ss++;
		i++;
	}
	return (NULL);
}
