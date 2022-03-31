/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:35:17 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/31 16:35:20 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*swap_signs(t_struct *s, char *str, char c, int i)
{
	while (str[i] && str[i] != '+' && str[i] != '-' && (s->plus || s->minus))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		c = str[i];
		str[i] = '0';
		str[0] = c;
	}
	while (str[i] && str[i] != ' ')
		i++;
	if (str[i] == ' ')
	{
		c = str[i];
		str[i] = '0';
		str[0] = c;
	}
	return (str);
}

void	set_default(t_struct *s)
{
	s->print = 0;
	s->length = 0;
	s->minus = 0;
	s->plus = 0;
	s->width = 0;
	s->zero = 0;
	s->space = 0;
	s->hash = 0;
	s->precision = 0;
	s->negative = 0;
	s->number = 0;
	s->star = 0;
	s->index = 0;
	s->floatprecis = 0;
	s->octal = 0;
}
