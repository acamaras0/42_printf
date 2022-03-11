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