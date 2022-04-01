/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:33:38 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/10 12:33:42 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** adds spaces or zeroes on the left side of the thing we 
** want our function to print.
** calls for the function swipe_signs, in case the if contidion
** is met.
*/

char	*convert_left(t_struct *s, char *str, int i, char c)
{
	char	*temp;
	char	*joined;
	int		n;

	n = 0;
	temp = ft_strcharnew(i, c);
	joined = ft_strjoin(temp, str);
	if (s->zero && !s->precision && s->width
		&& (s->plus || s->minus || !s->negative || s->space))
		joined = swap_signs(s, joined, c, i);
	ft_strdel(&temp);
	ft_strdel(&str);
	return (joined);
}

/*
** depending on the number we get from the substraction of the
** width and the length of the string, we have different if conditions
** with different flag combinations which call for the convert_left
** function, that will add accordingly spaces or zeroes on the 
** left side of the string.
*/

char	*align_to_left(t_struct *s, char *str, int i)
{
	char	*joined;

	i = s->width - ft_strlen(str);
	if (i > 0 && s->zero && s->precision > 0
		&& !(s->hash || s->plus || s->space))
		return (joined = convert_left(s, str, i, ' '));
	if (i > 0 && s->octal && s->hash && s->precision)
		return (joined = convert_left(s, str, i, ' '));
	if (i > 0 && s->zero == 0 && s->negative == 0 && !(s->precision && s->hash))
		return (joined = convert_left(s, str, i, ' '));
	if (i > 0 && s->zero == 0 && s->negative == 1 && s->plus == 0)
		return (joined = convert_left(s, str, i - 2, ' '));
	if (i > 0 && s->zero == 0 && s->negative == 1 && s->plus == 1)
		return (joined = convert_left(s, str, i - 1, ' '));
	if (i > 0 && !s->plus && !s->negative && !s->hash)
		return (joined = convert_left(s, str, i, '0'));
	if (i > 0 && (s->negative == 1 || s->plus == 1) && s->hash == 0)
		return (joined = convert_left(s, str, i, '0'));
	if (i > 0 && s->hash == 1 && !s->precision && !s->space && !s->octal)
		return (joined = convert_left(s, str, i - 2, '0'));
	if (i > 0 && s->hash == 1 && !s->precision && !s->space && s->octal)
		return (joined = convert_left(s, str, i, '0'));
	if (i > 0 && s->hash == 0 && !s->precision && !s->space)
		return (joined = convert_left(s, str, i, '0'));
	return (str);
}

/*
** adds spaces or zeroes on the right side of the thing we 
** want our function to print.
*/

static char	*convert_right(char *str, int i, char c)
{
	char	*temp;
	char	*joined;
	int		n;

	n = 0;
	temp = ft_strcharnew(i, c);
	joined = ft_strjoin(str, temp);
	ft_strdel(&temp);
	ft_strdel(&str);
	return (joined);
}

/*
** depending on the number we get from the substraction of the
** width and the length of the string, we have different if conditions
** with different flag combinations which call for the convert_right
** function, that will add accordingly spaces or zeroes on the 
** right side of the string.
*/

char	*align_to_right(t_struct *s, char *str)
{
	int		i;
	char	*joined;

	joined = NULL;
	i = s->width - ft_strlen(str);
	if (i > 0 && s->hash && s->octal && s->zero)
		return (joined = convert_right(str, i, ' '));
	if (i > 0 && s->negative == 1)
		return (joined = convert_right(str, i - 1, ' '));
	else if (i > 0 && s->zero == 1 && s->hash == 1)
		return (joined = convert_right(str, i - 2, ' '));
	else if (i > 0)
		return (joined = convert_right(str, i, ' '));
	return (str);
}
