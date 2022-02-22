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

static unsigned int	ft_numlen(long value, unsigned int base)
{
	int	size;

	size = 1;
	if (base != 10 && value < 0)
		value = -value;
	if (value < 0)
	size ++;
	while (value / base)
	{
		size++;
		value /= base;
	}
	return (size);
}

static char	*helper( char *str, char *refbase, long nb, int base)
{
	unsigned long long	i;

	i = ft_numlen(nb, base);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		i++;
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * (-1);
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
	unsigned long long		i;
	long					nb;

	nb = n;
	refbase = "0123456789ABCDEF";
	i = ft_numlen(nb, base);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str || base < 2 || base > 16)
		return (NULL);
	return (helper(str, refbase, nb, base));
}
