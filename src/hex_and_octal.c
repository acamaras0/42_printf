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

static char 	*joined(t_struct *s, char *str)
{
	char	*join;
	char 	*temp;

	join = NULL;
	if (s->bigx == 1)
		join = ft_strjoin("0X", str);
	else if (s->bigx == 0)
		join = ft_strjoin("0x", str);
	if (!join)
	{
		temp = join;
		ft_strdel(&join);
	}
	return (join);
}

static char	*swap(t_struct *s, char *str, int n)
{
	if (s->minus == 1 && n > 0)
		str = align_to_right(s, str);
	else if (s->minus == 0 && n > 0)
		str = align_to_left(s, str);
	//if ((s->hash == 1 && str[1] != 0) && s->zero == 0)
	str = joined(s, str);
	return (str);	
}

void	ifhex(t_struct *s, va_list args)
{
	char	*str;
	int		n;

	s->bigx = 1;
	str = length_modifiers_hex(s, 0, args);
	n = ft_strlen(str);
	if (s->hash == 1 && s->zero == 1)
			str = swap(s, str, n);
	else
	{
		if ((s->hash == 1 && str[1] != 0) && s->zero == 0)
			str = joined(s, str);
		if (s->minus == 1 && n > 0)
			str = align_to_right(s, str);
		else if (s->minus == 0 && n > 0)
			str = align_to_left(s, str);
	}
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
	n = ft_strlen(str);
	if (s->hash == 1 && s->zero == 1)
			str = swap(s, str, n);
	else
	{
		if ((s->hash == 1 && str[1] != 0) && s->zero == 0)
			str = joined(s, str);
		if (s->minus == 1 && n > 0)
			str = align_to_right(s, str);
		else if (s->minus == 0 && n > 0)
			str = align_to_left(s, str);
	}
	while (str[j])
	{
		if (str[j] >= 65 && str[j] <= 90)
			str[j] += 32;
		j++;
	}
	ft_putstr(str);
	s->print += ft_strlen(str);
	ft_strdel(&str);
}

void	ifoctal(t_struct *s, va_list args)
{
	char	*str;
	int		n;

	str = length_modifiers_oct(s, 0, args);
	n = ft_strlen(str);
	if (s->minus == 1 && n > 0)
		str = align_to_right(s, str);
	else if (s->minus == 0 && n > 0)
		str = align_to_left(s, str);
	if (s->hash == 1)
		ft_putchar('0');
	ft_putstr(str);
	s->print += ft_strlen(str);
	ft_strdel(&str);
}
