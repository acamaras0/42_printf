/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iffloat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:07:25 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/22 12:07:28 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	iffloat(t_struct *s, va_list args)
{
	char	*str;

	str = length_modifiers_float(s, 0, args);

	
	ft_putstr(str);
	s->print += ft_strlen(str);
	ft_strdel(&str);
}
