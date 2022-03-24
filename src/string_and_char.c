/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_and_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:06:26 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/07 17:06:29 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ifpercent(t_struct *s)
{
	int		n;
	char	p;

	n = s->width - 1;
	p = '%';
	if (s->minus == 0 && s->width)
	{
		if (s->zero == 1)
			put_zeroes(s, n);
		else
			put_spaces(s, n);
	}
	if (s->minus == 1 && s->width)
	{
		write(1, &p, 1);
		put_spaces(s, n);
	}
	else
		write(1, &p, 1);
	s->print++;
}

void	ifchar(t_struct *s, va_list args)
{
	unsigned char	c;
	int				n;

	c = (unsigned char)va_arg(args, int);
	n = s->width - 1;
	if (s->minus == 0 && s->width)
	{
		if (s->zero == 1)
			put_zeroes(s, n);
		else
			put_spaces(s, n);
	}
	if (s->minus == 1 && s->width)
	{
		write(1, &c, 1);
		put_spaces(s, n);
	}
	else
		write(1, &c, 1);
	s->print++;
}

static char	*string_precision(char *str, int i)
{
	char		*temp;
	size_t		len;

	len = ft_strlen(str);
	if (i > 0 && (size_t)i <= len)
	{
		temp = ft_strndup(str, i);
		str = temp;
		ft_strdel(&temp);
		return (str);
	}
	if (i == -1)
		str = "";
	return (str);
}

void	ifstring(t_struct *s, va_list args)
{
	char	*str;
	int		i;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	str = string_precision(str, s->precision);
	i = s->width - ft_strlen(str);
	if (i > 0 && s->minus == 0)
	{
		if (s->zero == 1)
			put_zeroes(s, i);
		else
			put_spaces(s, i);
		write(1, str, ft_strlen(str));
	}
	else if (i > 0 && s->minus == 1)
	{
		write(1, str, ft_strlen(str));
		put_spaces(s, i);
	}
	else
		write(1, str, ft_strlen(str));
	s->print += ft_strlen(str);
}
