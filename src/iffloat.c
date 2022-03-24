/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:07:25 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/22 12:07:28 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	iffloat(t_struct *s, va_list args)
{
	long double	i;
	char		*str;

	i = 0;
	str = length_modifiers_float(s, i, args);
	s->number = s->precision - ft_strlen(str);
	if (((s->plus && !s->negative) || s->negative) && str[0] != '-')
		str = add_zero_plus_minus(str, s, '+', 3);
	if (s->space && !s->negative)
	{
		s->number = 1;
		str = add_zero_plus_minus(str, s, ' ', 2);
	}
	if (s->minus)
		str = align_to_right(s, str);
	if (!s->minus)
		str = align_to_left(s, str);
	write(1, str, ft_strlen(str));
	s->print += ft_strlen(str);
	ft_strdel(&str);
}
