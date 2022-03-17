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

void	int_helper(t_struct *s)
{
	if (s->plus == 1 && s->negative == 0)
	{
		s->print++;
		ft_putchar('+');
	}
	else if (s->space == 1 && s->negative == 0)
	{
		s->print++;
		ft_putchar(' ');
	}
	if (s->negative == 1)
	{
		s->print++;
		ft_putchar('-');
		s->negative = 0;
	}
}

void	ifnum(t_struct *s, va_list args)
{
	char		*str;
	int			i;

	str = length_modifiers_int(s, 0, args);
	i = ft_atoi(str);
	s->number = s->precision - ft_strlen(str);
	if (s->width && s->minus)
	{
		str = align_to_right(s, str);
	}
	else if (s->width && !s->minus)
	{
		str = align_to_left(s, str);
	}
	int_helper(s);
	ft_putstr(str);
	s->print += ft_strlen(str);
	ft_strdel(&str);
}

void	ifunsigned(t_struct *s, va_list args)
{
	char	*str;

	str = length_modifiers_uint(s, 0, args);
	if (str[0] == '0' && s->precision == -1)
		str[0] = '\0';
	s->number = s->precision - ft_strlen(str);
	if (s->width && s->zero && s->minus)
		str = align_to_right(s, str);
	else if (s->width && !s->minus)
		str = align_to_left(s, str);
	ft_putstr(str);
	s->print += ft_strlen(str);
	ft_strdel(&str);
}
