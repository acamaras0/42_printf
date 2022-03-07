/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:53:45 by acamaras          #+#    #+#             */
/*   Updated: 2022/02/17 15:29:52 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_numlen(unsigned long long value, int base)
{
	int	size;

	size = 0;
	if (value == 0)
		size ++;
	while (value)
	{
		value /= base;
		size++;
	}
	return (size);
}

static char	*helper( char *str, char *refbase, unsigned long long nb, int base)
{
	unsigned long long	i;

	i = ft_numlen(nb, base);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		i++;
	}
	while (nb > 0)
	{
		str[i--] = refbase[nb % base];
		nb = nb / base;
	}
	return (str);
}

char	*ft_itoa_base(unsigned long long n, int base)
{
	char					*str;
	char					*refbase;
	unsigned long long		len;

	refbase = "0123456789ABCDEF";
	len = ft_numlen(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || base < 2 || base > 16)
		return (NULL);
	return (helper(str, refbase, n, base));
}
