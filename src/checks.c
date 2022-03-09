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
	while (ft_strchr(FLAGS, format[s->index]))
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
	while (ft_strchr(LENGTH, format[s->index] && format[s->index]))
		s->index++;
}

void	specifier_check(t_struct *s, char c, va_list args)
{
	if (c == 'c')
		ifchar(s, args);
	else if (c == 'd' || c == 'i')
		ifnum(s, args);
	else if (c == 's')
		ifstring(s, args);
	else if (c == '%')
		ifpercent(s);
	else if (c == 'p')
		ifpointer(s, args);
	else if (c == 'u')
		ifunsigned(s, args);
	else if (c == 'x')
		ifhex2(s, args);
	else if (c == 'X')
		ifhex(s, args);
	else if (c == 'o')
		ifoctal(s, args);
}

void	width_check(const char *format, t_struct *s, va_list args)
{
	if (format[s->index] == '*')
	{
		s->width = va_arg(args, int);
		//printf("1%d\n", s->width);
		if (s->width < 0)
		{
			s->minus = 1;
			s->width *= -1;
		}
		while (format[s->index] == '*')
		{
			s->index++;
			//printf("index: %d\n", s->index);
		}
	}
	//printf("indexxx: %d\n", s->index);
	if (format[s->index] >= '0' && format[s->index] <= '9')
	{
		s->width = ft_atoi(&format[s->index]);
		//printf("%d\n", s->width);
		printf("index1: %d\n", s->index);
	}
	while (format[s->index] >= '0' && format[s->index] <= '9')
		s->index++;
}

static void		precision_check(const char *format, t_struct *s, va_list args, int n)
{
	if (format[s->index] == '.')
	{
		s->precision = -1;
		s->index++;
		if (format[s->index] >= '0' && format [s->index] <= '9')
		{
			s->precision = ft_atoi(&format[s->index]);
			if (s->precision == 0)
				s->precision = -1;
		}
		else if (format[s->index] == '*')
		{
			n = va_arg(args, int);
			if (n >= 0)
				s->precision = 1;
			while(format[s->index == '*'])
				s->index++;
		}
	}
	printf("1: %d\n", s->index);
	while (format[s->index] >= '0' && format[s->index] <= '9')
		s->index++;
	printf("1: %d\n", s->index);
}

void	all_checks(const char *format, t_struct *s, va_list args)
{
	flags_check(format, s);
	width_check(format, s, args);
	precision_check(format, s, args, 0);
	//printf("index3: %d\n", s->index);
	//printf("%d\n", s->width);
	length_check(s, format);
}
