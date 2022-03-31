/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_and_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:05:23 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/07 17:05:30 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ifnum(t_struct *s, va_list args)
{
	char		*str;

	str = length_modifiers_int(s, 0, args);
	s->number = s->precision - ft_strlen(str);
	if (str[0] == '0' && s->precision == -1)
		str[0] = '\0';
	if (s->precision > 0 && s->number > 0)
		str = add_zero_plus_minus(str, s, '0', 1);
	if (s->space && !s->negative)
	{
		s->number = 1;
		if (s->zero && s->width)
			str = add_zero_plus_minus(str, s, '0', 2);
		str = add_zero_plus_minus(str, s, ' ', 2);
	}
	if ((s->plus && !s->negative) || s->negative)
		str = add_zero_plus_minus(str, s, '+', 3);
	if (s->minus)
		str = align_to_right(s, str);
	if (!s->minus)
		str = align_to_left(s, str, 0);
	write(1, str, ft_strlen(str));
	s->print += ft_strlen(str);
	ft_strdel(&str);
}

void	ifunsigned(t_struct *s, va_list args)
{
	char	*str;

	str = length_modifiers_uint(s, 0, args);
	s->number = s->precision - ft_strlen(str);
	if (str[0] == '0' && s->precision == -1)
		str[0] = '\0';
	if (s->precision > 0 && s->number > 0)
		str = add_zero_plus_minus(str, s, '0', 1);
	if (s->number && s->minus)
		str = align_to_right(s, str);
	else if (s->number && !s->minus)
		str = align_to_left(s, str, 0);
	write(1, str, ft_strlen(str));
	s->print += ft_strlen(str);
	ft_strdel(&str);
}
