/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:59:09 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/15 20:25:44 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*s1;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	s1 = (char *)malloc(sizeof(char) * len + 1);
	if (!s1)
		return (NULL);
	while (i < len)
	{
		s1[i] = (*f)(s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
