/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:24:34 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/10 17:20:30 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;
	int				i;
	int				len;

	chr = (unsigned char)c;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == chr)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
