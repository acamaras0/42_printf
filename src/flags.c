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
