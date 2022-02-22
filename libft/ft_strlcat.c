/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:56:01 by acamaras          #+#    #+#             */
/*   Updated: 2022/02/17 15:26:26 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dest;
	size_t	srcs;

	j = 0;
	dest = (ft_strlen(dst));
	srcs = (ft_strlen(src));
	i = dest;
	if (dstsize < dest || dstsize < 1)
		return (dstsize + srcs);
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (dest + srcs);
}
