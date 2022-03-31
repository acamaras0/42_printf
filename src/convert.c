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

/*static char	*align_to_left_space(t_struct *s, char *str, char *joined, int i)
{
	
	return (str);
}*/

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
