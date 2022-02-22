/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:23:03 by acamaras          #+#    #+#             */
/*   Updated: 2022/02/17 15:25:31 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static char	*helper( char *str, unsigned long long i, long nb)
{
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
		str[i--] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned long long n)
{
	char					*str;
	unsigned long long		i;
	long					nb;

	nb = n;
	i = ft_nb_len(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	return (helper(str, i, nb));
}
