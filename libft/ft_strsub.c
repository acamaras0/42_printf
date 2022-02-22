/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:11:12 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/16 15:33:48 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	s1 = (char *)malloc(sizeof(char) * len + 1);
	if (!s1)
		return (NULL);
	while (len)
	{
		s1[i] = s[start + i];
		i++;
		len--;
	}
	s1[i] = '\0';
	return (s1);
}
