/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:44:40 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/15 20:23:36 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*s1;

	if (!s && !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	s1 = (char *)malloc(sizeof(char) * len + 1);
	if (!s1)
		return (NULL);
	while (i < len)
	{
		s1[i] = (*f)(i, (char)s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
