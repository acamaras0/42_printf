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

void	length(t_struct *s, const char *format)
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

void	get_formats(t_struct *s, char c, va_list args)
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

void	zero_struct(t_struct *s)
{
	s->print = 0;
	s->length = 0;
}

int	parse(const char *format, t_struct *s, va_list args, int pos)
{
	s->index = pos;
	if (ft_strchr(LENGTH, format[pos]))
		length(s, format);
	else
	{
		get_formats(s, format[pos], args);
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
			while (format[pos] != '\0' && ft_strchr(ALL, format[pos + 1]))
			{
				pos++;
				if (ft_strchr(CONVERSION, format[pos]))
				{
					pos = parse(format, s, args, pos) + 1;
					break ;
				}
				else
				{
				pos = parse(format, s, args, pos);
				}
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
