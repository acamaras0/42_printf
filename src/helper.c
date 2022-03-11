/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:32:43 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/08 13:32:45 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_zeroes(t_struct *s, int n)
{
	while (n > 0)
	{
		ft_putchar('0');
		n--;
		s->print++;
	}
}

void	put_spaces(t_struct *s, int n)
{
	while (n > 0)
	{
		ft_putchar(' ');
		n--;
		s->print++;
	}
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
