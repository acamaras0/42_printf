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

char	*ft_ftoa(long double fl, int prec, int d)
{
	int						i;
	char					*joined;
	char					*ip;
	char					*fp;
	unsigned long long		decimal;

	i = 1;
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
	while (prec -- > 0)
	{
		fl *= 10;
		decimal = fl;
		fl -= decimal;
		fp[i++] = decimal + '0';
	}
	joined = ft_strjoin(ip, fp);
	ft_strdel(&ip);
	ft_strdel(&fp);
	return (joined);
}

/*#include <stdio.h>
int main()
{
	char *s = NULL;

	s = ft_ftoa(1.56673, 4, 1);
	ft_putstr(s);
	ft_putchar('\n');
	printf("%.4f\n", 1.56673);
	return(0);
}*/
