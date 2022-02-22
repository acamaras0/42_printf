/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:08:32 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/12 17:39:43 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = ft_memalloc(size + 1);
	if (!s)
		return (NULL);
	while (i < size)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
