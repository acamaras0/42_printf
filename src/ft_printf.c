/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:18:27 by acamaras          #+#    #+#             */
/*   Updated: 2022/02/15 15:37:51 by acamaras         ###   ########.fr       */
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

void	zero_struct(t_struct *s)
{
	s->print = 0;
	s->length = 0;
	s->minus = 0;
	s->plus = 0;
	s->width = 0;
	s->zero = 0;
	s->space = 0;
	s->hash = 0;
}

int	parse(const char *format, t_struct *s, va_list args, int pos)
{
	s->index = pos;
	if (ft_strchr(FLAGS, format[pos]))
	{
		length_check(s, format); //fix the width, add precision
	}
	else
	{
		specifier_check(s, format[pos], args);
		zero_struct(s);
	}
	pos = s->index;
	if (format[pos] == '\0')
		return (pos);
	return (pos);
}

int	formato(const char *format, t_struct *s, va_list args, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%')
			s->print += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			while (ft_strchr(ALL, format[pos + 1]) && format[pos] != '\0')
			{
				pos++;
				if (ft_strchr(CONVERSION, format[pos]))
				{
					pos = parse(format, s, args, pos) + 1;
					break ;
				}
				else
					pos = parse(format, s, args, pos);
			}
			continue ;
		}
		pos++;
	}
	return (s->print);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_struct	*s;
	int			i;
	int			len;

	i = 0;
	s = (t_struct *)(malloc)(sizeof(t_struct));
	if (!s)
		return (0);
	zero_struct(s);
	s->form = (char *)format;
	va_start(args, format);
	len = ft_strlen(format);
	if (len == 0)
		return (0);
	if (len == 1 && format[0] == '%')
		return (0);
	i = formato(format, s, args, 0);
	va_end(args);
	free(s);
	return (i);
}
