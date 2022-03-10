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
	//printf("HERE %d %d\n", s->number, s->precision);
	s->number = s->precision - ft_strlen(str);
	//printf("HERE2 %d %d\n", s->number, s->precision);
	if (s->minus == 1)
		str = align_to_left(s, str);
	//else if (s->minus == 0)
		//str = align_to_right(s, str);
	ft_putstr(str);
	s->print += ft_strlen(str);
	ft_strdel(&str);
}

void	ifunsigned(t_struct *s, va_list args)
{
	char	*str;

	str = length_modifiers_uint(s, 0, args);
	ft_putstr(str);
	s->print += ft_strlen(str);
	ft_strdel(&str);
}
