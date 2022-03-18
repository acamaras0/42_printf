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

char	*to_lower(char *str)
{
	int j;

	j= 0;
	while (str[j])
	{
		if (str[j] >= 65 && str[j] <= 90)
			str[j] += 32;
		j++;
	}
	return (str);
}

char	*add_zero_plus_minus(char *str, t_struct *s, char c, int conv)
{
	char *temp;
	char *joined;

	if (conv == 0 && str[0] != 0 && c == '0')
	{
			joined = ft_strjoin("0", str);
	}
	if (conv == 1)
	{
		temp = ft_strcharnew(s->number, c);
		joined = ft_strjoin(temp, str);
		free(temp);
	}
	if (conv == 2 && (s->plus && !s->negative) || s->negative)
	{
		if (s->plus && !s->negative)
			joined = ft_strjoin("+", str);
		else if (s->negative)
			joined = ft_strjoin("-", str);
	}
	free(str);
	return (joined);
}