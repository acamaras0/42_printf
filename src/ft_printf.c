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

/*
** checks for flags, if flags found, we check what flag it is, if there is 
** width, precision and/or length modifiers.
** else calls for specifier check where, considering what specifier we get,
** we call for a function which handles the rest.
*/

int	parse(const char *format, t_struct *s, va_list args, int pos)
{
	s->index = pos;
	if (ft_strchr(FLAGS, format[pos]))
	{
		flags_check(format, s);
		width_check(format, s, args);
		precision_check(format, s, args, 0);
		length_check(s, format);
	}
	else
		specifier_check(s, format[pos], args);
	pos = s->index;
	if (format[pos] == '\0')
		return (pos);
	return (pos - 1);
}

/*
** checks for the format that comes after the "%" and calls for the parser
** in order to continue with the checks for flags, width, precision and length.
*/

int	formato(const char *format, t_struct *s, va_list args, int pos)
{
	while (format[pos] != '\0')
	{
		if (format[pos] != '%')
			s->print += write(1, &format[pos], 1);
		else if (format[pos] == '%')
		{
			if (!(ft_strchr(ALL, format[pos + 1]) || format[pos] == '\0'))
				break ;
			while (ft_strchr(ALL, format[pos + 1]) && format[pos] != '\0')
			{
				pos++;
				if (ft_strchr(CONVERSION, format[pos]))
				{
					pos = parse(format, s, args, pos) + 2;
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
	set_default(s);
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
