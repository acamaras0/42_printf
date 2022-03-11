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

char	*convert_left(char *str, int i, char c)
{
	char	*temp;
	char	*joined;
	int 	n;

	n = 0;
	temp = ft_strcharnew(i, c);
	joined = ft_strjoin(temp, str);
	ft_strdel(&temp);
	ft_strdel(&str);
	return (joined);
}

char	*align_to_left(t_struct *s, char *str)
{
	int i;
	char *joined;

	joined = NULL;
	i = s->width - ft_strlen(str);
	if (i > 0 && !s->zero)
		return (joined = convert_left(str, i, ' '));
	else if (i > 0 && s->zero == 1)
		return (joined = convert_left(str, i, '0')); 
	return (str);
}

char	*convert_right(char *str, int i, char c)
{
	char	*temp;
	char	*joined;
	int 	n;

	n = 0;
	temp = ft_strcharnew(i, c);
	joined = ft_strjoin(str, temp);
	ft_strdel(&temp);
	ft_strdel(&str);
	return (joined);
}

char	*align_to_right(t_struct *s, char *str)
{
	int i;
	char *joined;

	joined = NULL;
	i = s->width - ft_strlen(str);
	if (i > 0)
		return (joined = convert_right(str, i, ' '));
	else if (i > 0 && s->zero == 1)
		return (joined = convert_left(str, i, '0')); 
	return (str);
}

