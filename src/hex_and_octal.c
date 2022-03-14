/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex _and_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:05:43 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/07 17:05:46 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ifhex(t_struct *s, va_list args)
{
	char	*str;
	int		n;

	str = length_modifiers_hex(s, 0, args);
	n = ft_strlen(str);
	if (s->minus == 1 && n > 0)
		str = align_to_right(s, str);
	else if (s->minus == 0 && n > 0)
		str = align_to_left(s, str);
	ft_putstr(str);
	s->print += ft_strlen(str);
	ft_strdel(&str);
}

void	ifhex2(t_struct *s, va_list args)
{
	char	*str;
	int		j;
	int		n;

	j = 0;
	str = length_modifiers_hex(s, 0, args);
	while (str[j])
	{
		if (str[j] >= 65 && str[j] <= 90)
			str[j] += 32;
		j++;
	}
	n = ft_strlen(str);
	if (s->minus == 1 && n > 0)
		str = align_to_right(s, str);
	else if (s->minus == 0 && n > 0)
		str = align_to_left(s, str);
	ft_putstr(str);
	s->print += ft_strlen(str);
	ft_strdel(&str);
}

void	ifoctal(t_struct *s, va_list args)
{
	char	*str;
	int n;

	str = length_modifiers_oct(s, 0, args);
	n = ft_strlen(str);
	if (s->minus == 1 && n > 0)
		str = align_to_right(s, str);
	else if (s->minus == 0 && n > 0)
		str = align_to_left(s, str);
	s->print += ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
}
