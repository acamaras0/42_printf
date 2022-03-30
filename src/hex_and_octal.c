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

static char	*joined(t_struct *s, char *str)
{
	char	*join;
	char	*temp;
	int		i;

	join = NULL;
	temp = NULL;
	i = s->width - ft_strlen(str);
	s->number = s->precision - ft_strlen(str);
	temp = ft_strjoin("0X", str);
	ft_strdel(&str);
	if (i > 0 && s->hash && s->precision)
		return (join = convert_left(s, temp, i - 2, ' '));
	join = ft_strdup(temp);
	ft_strdel(&temp);
	return (join);
}

static char	*swap(t_struct *s, char *str, int n)
{
	s->number = s->precision - ft_strlen(str);
	if (s->minus == 1 && n > 0)
		str = align_to_right(s, str);
	else if (s->minus == 0 && n > 0)
		str = align_to_left(s, str);
	if (!s->precision)
		str = joined(s, str);
	return (str);
}

static void	more_hex_checks(t_struct *s, char *str, int n)
{
	if (!s->hash && !s->octal)
		s->number = s->precision - n;
	if (s->hash && str[1] == '\0' && !s->octal)
		s->number = s->precision - n;
	if (s->precision > 0 && !s->octal)
		s->number = s->precision - ft_strlen(str);
	if (((str[0] == '0' && s->precision == -1) || str[0] == '\0') && s->octal)
		str[0] = '\0';
}

void	ifhex(t_struct *s, va_list args, char c)
{
	char	*str;

	str = length_modifiers_hex(s, 0, args);
	if (str[0] == '0' && s->precision == -1)
		str[0] = '\0';
	if (s->hash == 1 && s->zero == 1 && str[0] != '\0' && str[0] != '0')
		str = swap(s, str, ft_strlen(str));
	if (s->hash && str[1] != 0 && !s->zero && ft_strlen(str) > 0
		&& !(s->hash && s->precision))
		str = joined(s, str);
	more_hex_checks(s, str, ft_strlen(str));
	if (s->precision > 0 && s->number > 0)
		str = add_zero_plus_minus(str, s, '0', 1);
	if (s->minus == 1)
		str = align_to_right(s, str);
	else if (s->minus == 0)
		str = align_to_left(s, str);
	if (s->hash && s->precision > 0)
		str = joined(s, str);
	if (c == 'x')
		str = to_lower(str);
	write(1, str, ft_strlen(str));
	s->print += ft_strlen(str);
	ft_strdel(&str);
}

void	ifoctal(t_struct *s, va_list args)
{
	char			*str;
	char			*temp;
	unsigned long	n;

	n = 0;
	s->octal = 1;
	str = length_modifiers_oct(s, n, args);
	more_hex_checks(s, str, n);
	temp = ft_strdup(str);
	if (s->hash == 1 && str[0] != '0')
	{
		ft_strdel(&str);
		str = ft_strjoin("0", temp);
	}
	s->number = s->precision - ft_strlen(str);
	if (s->precision > 0 && s->number > 0)
		str = add_zero_plus_minus(str, s, '0', 1);
	if (s->minus == 1)
		str = align_to_right(s, str);
	else if (s->minus == 0)
		str = align_to_left(s, str);
	write(1, str, ft_strlen(str));
	s->print += ft_strlen(str);
	ft_strdel(&temp);
	ft_strdel(&str);
}
