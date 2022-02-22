/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:57:12 by acamaras          #+#    #+#             */
/*   Updated: 2021/11/10 18:59:21 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	minus;
	int	i;
	int	result;

	i = 0;
	minus = 1;
	result = 0;
	while (ft_iswhitespace(str[i]) == 0)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		minus = -1 * (str[i] - '-' + 1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * minus);
}
