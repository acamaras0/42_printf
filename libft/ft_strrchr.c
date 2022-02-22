/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:52:05 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/22 16:21:39 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	chr;
	char			*s1;
	int				i;

	chr = (unsigned char)c;
	s1 = (char *)s;
	i = ft_strlen(s1);
	s1 += i;
	if (!s1)
	{
		return (NULL);
	}
	while (i >= 0)
	{
		if (*s1 == chr)
		{
			return (s1);
		}
		i--;
		s1--;
	}
	return (NULL);
}
