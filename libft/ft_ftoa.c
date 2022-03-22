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

static long double		round(long double fl, int prec)
{
	long double		round;
	int				decimal;

	round = 0.5;
	if (fl < 0)
		round *= -1;
	decimal = 0;
	while (decimal < prec)
	{
		round /= 10;
		decimal++;
	}
	return (round);
}

char	*ft_ftoa(long double fl, int prec, int d)
{
	int						i;
	char					*joined;
	char					*ip;
	char					*fp;
	unsigned long long		decimal;

	i = 1;
	fl = fl + round(prec, fl);
	if (fl < 0)
		fl *= -1;
	decimal = fl;
	ip = ft_itoa(decimal);
	if (prec)
		fl -= decimal;
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

/*int main()
{
	char *s = NULL;

	s = ft_ftoa(1.56673, 10, 4);
	ft_putstr(s);
	return(0);
} */