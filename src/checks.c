/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:26:19 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/07 16:26:23 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flags_check(const char *format, t_struct *s)
{
	while (ft_strchr("#0-+ ", format[s->index]))
	{
		if (format[s->index] == '#')
			s->hash = 1;
		if (format[s->index] == '0')
			s->zero = 1;
		if (format[s->index] == '-')
			s->minus = 1;
		if (format[s->index] == '+')
			s->plus = 1;
		if (format[s->index] == ' ')
			s->space = 1;
		s->index++;
	}
	if (s->plus == 1)
		s->space = 0;
}

void	length_check(t_struct *s, const char *format)
{
	if (format[s->index] == 'l')
	{
		if (format[s->index + 1] == 'l')
			s->length = LL;
		else if (format[s->index - 1] != 'l')
			s->length = L;
	}
	if (format[s->index] == 'h')
	{
		if (format[s->index + 1] == 'h')
			s->length = HH;
		else if (format[s->index - 1] != 'h')
			s->length = H;
	}
	if (format[s->index] == 'L')
		s->length = BL;
	while (ft_strchr(LENGTH, format[s->index]) && format[s->index])
		s->index++;
}

void	width_check(const char *format, t_struct *s, va_list args)
{
	if (format[s->index] == '*')
	{
		s->width = va_arg(args, int);
		s->star = 1;
		if (s->width < 0)
		{
			s->minus = 1;
			s->width *= -1;
		}
		while (format[s->index] == '*')
			s->index++;
	}
	if (format[s->index] >= '0' && format[s->index] <= '9')
	{
		s->width = ft_atoi(&format[s->index]);
	}
	while (format[s->index] >= '0' && format[s->index] <= '9')
		s->index++;
}

static void	precision_helper(const char *f, t_struct *s, va_list args, int n)
{
	if (f[s->index] >= '0' && f[s->index] <= '9')
	{
		s->precision = ft_atoi(&f[s->index]);
		if (s->precision == 0)
			s->precision = -1;
		if (s->precision > 0)
			s->floatprecis = 1;
	}
	else if (f[s->index] == '*')
	{
		n = va_arg(args, int);
		if (n >= 0)
		{
			s->precision = n;
			s->floatprecis = 1;
		}
		while (f[s->index] == '*')
			s->index++;
	}
}

void	precision_check(const char *format, t_struct *s, va_list args, int n)
{
	if (format[s->index] == '.')
	{
		s->precision = -1;
		s->floatprecis = 0;
		s->index++;
		precision_helper(format, s, args, n);
	}
	while (format[s->index] >= '0' && format[s->index] <= '9')
		s->index++;
}
