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
		ft_putchar('%');
		put_spaces(s, n);
	}
	else
		ft_putchar('%');
	s->print++;
}

void	ifchar(t_struct *s, va_list args)
{
	unsigned char	c;

	c = (unsigned char)va_arg(args, int);
	ft_putchar(c);
	s->print++;
}

void	ifstring(t_struct *s, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return ;
	}
	else
		ft_putstr(str);
	s->print += ft_strlen(str);
}
