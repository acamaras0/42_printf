/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:28:12 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/11 18:28:14 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ifpointer(t_struct *s, va_list args)
{
	unsigned long long	i;
	int					j;
	char				*str;
	char				*joined;

	j = 0;
	i = va_arg(args, unsigned long long);
	str = ft_itoa_base((unsigned long long)i, 16);
	while (str[j])
	{
		if (str[j] >= 65 && str[j] <= 90)
			str[j] += 32;
		j++;
	}
	joined = ft_strjoin("0x", str);
	ft_putstr(joined);
	s->print += ft_strlen(joined);
	ft_strdel(&str);
	ft_strdel(&joined);
}
