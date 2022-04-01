/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:28:12 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/11 18:28:14 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	pointer_checks(t_struct *s, char *joined, int n)
{
	if (n > 0 && s->zero == 0 && s->minus == 0)
		put_spaces(s, n);
	if (n > 0 && s->zero == 1 && s->minus == 1)
		put_zeroes(s, n);
	if (n > 0 && s->minus == 1)
	{
		write(1, joined, ft_strlen(joined));
		put_spaces(s, n);
	}
	else
		write(1, joined, ft_strlen(joined));
}

void	ifpointer(t_struct *s, va_list args)
{
	unsigned long long	i;
	int					n;
	char				*str;
	char				*joined;

	i = va_arg(args, unsigned long long);
	str = ft_itoa_base((unsigned long long)i, 16);
	if (str[0] == '0' && s->precision == -1)
		str[0] = '\0';
	if (str)
		to_lower(str);
	joined = ft_strjoin("0x", str);
	n = s->width - (ft_strlen(joined));
	pointer_checks(s, joined, n);
	s->print += ft_strlen(joined);
	ft_strdel(&str);
	ft_strdel(&joined);
}
