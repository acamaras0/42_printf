/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:51:35 by acamaras          #+#    #+#             */
/*   Updated: 2022/03/22 14:51:37 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	rounding(int precision, long double f)
{
	long double	rounding;
	int			d;

	rounding = 0.5;
	if (f < 0)
		rounding *= -1;
	d = 0;
	while (d++ < precision)
		rounding /= 10.0;
	return (rounding);
}

void	checko(int prec, unsigned long long decimal, long double fl, char *fp)
{
	int	i;

	i = 1;
	while (prec -- > 0)
	{
		fl *= 10;
		decimal = fl;
		fl -= decimal;
		fp[i++] = decimal + '0';
	}
}

char	*ft_ftoa(long double fl, int prec, int d)
{
	char					*joined;
	char					*ip;
	char					*fp;
	unsigned long long		decimal;

	fl = fl + rounding(prec, fl);
	if (fl < 0)
		fl *= -1;
	decimal = fl;
	ip = ft_itoa(decimal);
	if (prec)
		fl = fl - decimal;
	fp = ft_strnew(prec + 2);
	if (d)
		fp[0] = '.';
	else
		fp[0] = '\0';
	checko(prec, decimal, fl, fp);
	joined = ft_strjoin(ip, fp);
	ft_strdel(&ip);
	ft_strdel(&fp);
	return (joined);
}
