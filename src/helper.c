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

/*
** prints zeroes
*/

void	put_zeroes(t_struct *s, int n)
{
	char	z;

	z = '0';
	while (n > 0)
	{
		write(1, &z, 1);
		n--;
		s->print++;
	}
}

/*
** prints spaces
*/

void	put_spaces(t_struct *s, int n)
{
	char	sp;

	sp = ' ';
	while (n > 0)
	{
		write(1, &sp, 1);
		n--;
		s->print++;
	}
}

/*
** checks for the specifier and calls accordingly for the function
** that deals with that precise specifier.
*/

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
	else if (c == 'x' || c == 'X')
		ifhex(s, args, c);
	else if (c == 'o')
		ifoctal(s, args);
	else if (c == 'f')
		iffloat(s, args);
}

/*
** turns upper case letters to lower case
** it is used for pointers and hexadecimal handler
** because my ft_itoa_base is only printing upper case
** letters.
*/

char	*to_lower(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] >= 65 && str[j] <= 90)
			str[j] += 32;
		j++;
	}
	return (str);
}

/*
** adds zeroes, plus or minus depending on what convertion we call
** this function helps for when we have to print a negative number
** or when we have the "+" flag or precision.
*/

char	*add_zero_plus_minus(char *str, t_struct *s, char c, int conv)
{
	char	*temp;
	char	*joined;

	if (conv == 1 || conv == 2)
	{
		temp = ft_strcharnew(s->number, c);
		joined = ft_strjoin(temp, str);
		ft_strdel(&temp);
	}
	if (conv == 3)
	{
		if ((s->plus && !s->negative) || s->negative)
		{
			if (s->plus && !s->negative)
				joined = ft_strjoin("+", str);
			else if (s->negative)
			{
				joined = ft_strjoin("-", str);
				s->negative = 0;
			}
		}
	}
	ft_strdel(&str);
	return (joined);
}
