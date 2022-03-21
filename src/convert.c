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

char	*swap_signs(char *str, char c, int i)
{
	while (str[i] && str[i] != '+' && str[i] != '-')
		i++;
	if(str[i] == '+' || str[i] == '-')
	{
		c = str[i];
		str[i] = '0';
		str[0] = c;
	}
	return (str);
}

char	*convert_left(t_struct *s, char *str, int i, char c)
{
	char	*temp;
	char	*joined;
	int		n;

	n = 0;
	temp = ft_strcharnew(i, c);
	joined = ft_strjoin(temp, str);
	if (s->zero && s->width && ((s->plus || s->minus) || s->negative))
		joined = swap_signs(joined, c, i);
	//printf("\nHERE: %d\n", i);
	if (!temp || !str)
	{
		ft_strdel(&temp);
		ft_strdel(&str);
	}
	return (joined);
}

char	*align_to_left(t_struct *s, char *str)
{
	int		i;
	char	*joined;

	joined = NULL;
	i = s->width - ft_strlen(str);
	if (i > 0 && s->zero == 1 && s->precision > 0 && !(s->hash && s->space && s->plus && s->minus))
		joined = convert_left(s, str, i , ' ');
	if (i > 0 && s->zero == 0 && s->negative == 0)
		return (joined = convert_left(s, str, i , ' '));
	else if (i > 0 && s->zero == 0 && s->negative == 1 && s->plus == 0)
		return (joined = convert_left(s, str, i - 2 , ' '));
	else if (i > 0 && s->zero == 0 && s->negative == 1 && s->plus == 1)
		return (joined = convert_left(s, str, i - 1, ' '));



	else if (i > 0 && s->plus == 0 && s->negative == 0 && s->hash == 0 && !s->precision)
		return (joined = convert_left(s, str, i , '0'));
	else if (i > 0 && (s->negative == 1 || s->plus == 1) && s->hash == 0 && !s->precision)
		return (joined = convert_left(s, str, i, '0'));
	else if (i > 0 && s->hash == 1 && !s->precision)
		return (joined = convert_left(s, str, i - 2, '0'));
	else if (i > 0 && s->hash == 0 && !s->precision)
		return (joined = convert_left(s, str, i, '0'));
	return (str);
}

char	*convert_right(char *str, int i, char c)
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
	if (i > 0 && s->negative == 1)
		return (joined = convert_right(str, i - 1, ' '));
	else if (i > 0 && s->zero == 1 && s->hash == 1)
		return (joined = convert_right(str, i - 2, ' '));
	else if (i > 0)
		return (joined = convert_right(str, i, ' '));
	return (str);
}
